#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    vector<string> words = { "aya", "ye", "woo", "ma" };
    int answer = 0;
    for (string s : babbling)
    {
        int idx = 0;

        while (idx < s.size())
        {
            bool ok = false;

            for (string word : words)
            {
                if (s.compare(idx, word.size(), word) == 0)
                {
                    idx += word.size();
                    ok = true;
                    break;
                }
            }

            if (!ok)
                break;
        }

        if (idx == s.size())
            answer++;
    }

    return answer;
}