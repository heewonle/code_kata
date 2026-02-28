# ===========================
# rename_to_ascii.ps1
# - 특정 경로 내 모든 파일/폴더 목록 저장
# - ASCII(영문/숫자/_/-/.)로 안전 변환한 이름 매핑 저장
# - 충돌 방지(중복이면 _2, _3 붙임)
# - 실제 리네임 수행(원하면 -WhatIf 로 드라이런 가능)
# ===========================

param(
  [Parameter(Mandatory=$true)]
  [string]$RootPath,

  [string]$OutDir = $PWD.Path,

  [switch]$DryRun
)

$ErrorActionPreference = "Stop"

function To-AsciiSafeName([string]$name) {
  # 확장자 유지 목적: 파일명/확장자 분리
  $base = [System.IO.Path]::GetFileNameWithoutExtension($name)
  $ext  = [System.IO.Path]::GetExtension($name)

  # 1) 유니코드 정규화
  $norm = $base.Normalize([Text.NormalizationForm]::FormKC)

  # 2) 공백류를 언더스코어로
  $norm = ($norm -replace '\s+', '_')

  # 3) ASCII만 남기고 나머지는 제거(필요하면 '-'로 바꿔도 됨)
  # 허용: A-Z a-z 0-9 _ - .
  $ascii = ($norm.ToCharArray() | ForEach-Object {
    if ($_ -match '[A-Za-z0-9_\-\.]') { $_ } else { '_' }
  }) -join ''

  # 4) 연속 '_' 정리, 앞/뒤 '_' 제거, 비어있으면 fallback
  $ascii = ($ascii -replace '_{2,}', '_').Trim('_')
  if ([string]::IsNullOrWhiteSpace($ascii)) { $ascii = "item" }

  return "$ascii$ext"
}

# 출력 파일 경로
$ts = (Get-Date).ToString("yyyyMMdd_HHmmss")
$fullListPath = Join-Path $OutDir "filelist_original_$ts.txt"
$mapPath      = Join-Path $OutDir "rename_map_$ts.tsv"
$resultPath   = Join-Path $OutDir "rename_result_$ts.tsv"

# 0) 경로 검증
$root = Resolve-Path $RootPath
$root = $root.Path

# 1) 원본 리스트 저장 (상대경로)
$items = Get-ChildItem -LiteralPath $root -Recurse -Force
$relPaths = $items | ForEach-Object {
  $_.FullName.Substring($root.Length).TrimStart('\')
}
$relPaths | Set-Content -LiteralPath $fullListPath -Encoding UTF8

# 2) 매핑 만들기 (폴더 먼저, 파일 나중에가 아님 -> 실제 리네임은 "깊은 것부터" 처리해야 안전)
# 충돌 방지용: 같은 디렉토리 내에서 중복 체크
$map = New-Object System.Collections.Generic.List[object]

foreach ($it in $items) {
  $rel = $it.FullName.Substring($root.Length).TrimStart('\')
  $dir = Split-Path -Path $rel -Parent
  $oldName = $it.Name
  $newName = To-AsciiSafeName $oldName

  $map.Add([pscustomobject]@{
    FullPath = $it.FullName
    RelPath  = $rel
    ParentRel= $dir
    OldName  = $oldName
    NewName0 = $newName
    IsDir    = $it.PSIsContainer
  })
}

# 3) 충돌 해결(같은 폴더 + 같은 NewName0 이면 _2, _3...)
# 폴더/파일 각각 독립적으로 충돌 체크
$grouped = $map | Group-Object ParentRel, NewName0, IsDir
foreach ($g in $grouped) {
  if ($g.Count -le 1) {
    $g.Group | ForEach-Object { $_ | Add-Member -NotePropertyName NewName -NotePropertyValue $_.NewName0 -Force }
    continue
  }

  $i = 1
  foreach ($row in $g.Group) {
    $i++
    $base = [System.IO.Path]::GetFileNameWithoutExtension($row.NewName0)
    $ext  = [System.IO.Path]::GetExtension($row.NewName0)
    $row | Add-Member -NotePropertyName NewName -NotePropertyValue ("{0}_{1}{2}" -f $base, ($i-1), $ext) -Force
  }
}

# 4) 매핑 파일 저장 (TSV)
"RelPath`tIsDir`tOldName`tNewName" | Set-Content -LiteralPath $mapPath -Encoding UTF8
$map | Sort-Object RelPath | ForEach-Object {
  "{0}`t{1}`t{2}`t{3}" -f $_.RelPath, $_.IsDir, $_.OldName, $_.NewName
} | Add-Content -LiteralPath $mapPath -Encoding UTF8

# 5) 실제 리네임: "가장 깊은 경로부터" (자식 먼저, 부모 나중에)
# - 폴더/파일 둘 다 깊이 큰 순서로 처리
$ordered = $map | Sort-Object { ($_.RelPath -split '\\').Count } -Descending

$results = New-Object System.Collections.Generic.List[string]
foreach ($row in $ordered) {
  if ($row.OldName -ceq $row.NewName) { continue } # 이미 동일하면 스킵

  $parent = Split-Path -LiteralPath $row.FullPath -Parent
  $src    = $row.FullPath
  $dst    = Join-Path $parent $row.NewName

  if (Test-Path -LiteralPath $dst) {
    $results.Add("SKIP`t$($row.RelPath)`tDEST_EXISTS`t$dst")
    continue
  }

  if ($DryRun) {
    $results.Add("DRYRUN`t$($row.RelPath)`t$src`t$dst")
  } else {
    Rename-Item -LiteralPath $src -NewName $row.NewName
    $results.Add("OK`t$($row.RelPath)`t$src`t$dst")
  }
}

"Status`tRelPath`tFrom`tToOrReason" | Set-Content -LiteralPath $resultPath -Encoding UTF8
$results | Add-Content -LiteralPath $resultPath -Encoding UTF8

Write-Host "Saved original list : $fullListPath"
Write-Host "Saved rename map    : $mapPath"
Write-Host "Saved rename result : $resultPath"
if ($DryRun) { Write-Host "DryRun enabled: no changes applied." }