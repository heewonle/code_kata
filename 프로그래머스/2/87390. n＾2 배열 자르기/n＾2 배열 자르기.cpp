#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve((size_t)(right - left + 1));
    for(long long i=left; i<=right; i++){
        long long row_num = i/n +1;
        long long col_num = i - (row_num -1)*n +1;
        answer.push_back(max(row_num,col_num));
    }
    return answer;
}