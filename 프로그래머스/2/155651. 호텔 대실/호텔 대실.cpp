#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline int ToMinute(const string& s)
{
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60
         + ((s[3] - '0') * 10 + (s[4] - '0'));
}

int solution(vector<vector<string>> book_time)
{
    int diff[1461] = {0};

    for (const auto& book : book_time)
    {
        const int start = ToMinute(book[0]);
        const int end = ToMinute(book[1]) + 10;

        ++diff[start];
        --diff[end];
    }

    int answer = 0;
    int current = 0;

    for (int i = 0; i < 1461; ++i)
    {
        current += diff[i];
        if (current > answer)
        {
            answer = current;
        }
    }

    return answer;
}