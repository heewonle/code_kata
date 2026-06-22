#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int video_min = stoi(video_len.substr(0, 2));
    int video_sec = stoi(video_len.substr(3, 2));

    int minute = stoi(pos.substr(0, 2));
    int second = stoi(pos.substr(3, 2));

    int op_start_min = stoi(op_start.substr(0, 2));
    int op_start_sec = stoi(op_start.substr(3, 2));
    int op_end_min = stoi(op_end.substr(0, 2));
    int op_end_sec = stoi(op_end.substr(3, 2));

    auto isOpening = [&]() {
        int cur = minute * 60 + second;
        int start = op_start_min * 60 + op_start_sec;
        int end = op_end_min * 60 + op_end_sec;

        return cur >= start && cur <= end;
    };

    if (isOpening()) {
        minute = op_end_min;
        second = op_end_sec;
    }

    for (string s : commands) {
        if (s == "next") {
            second = second + 10;
        }

        if (s == "prev") {
            second = second - 10;
        }

        if (second >= 60) {
            second -= 60;
            minute += 1;
        }

        if (second < 0) {
            second += 60;
            minute -= 1;
        }

        if (minute < 0) {
            minute = 0;
            second = 0;
        }

        if (minute > video_min || (minute == video_min && second > video_sec)) {
            minute = video_min;
            second = video_sec;
        }

        if (isOpening()) {
            minute = op_end_min;
            second = op_end_sec;
        }
    }

    string mins = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    string sec = (second < 10) ? "0" + to_string(second) : to_string(second);

    answer = mins + ":" + sec;
    return answer;
}