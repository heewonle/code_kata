#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for (char c : new_id) {
        c = tolower(c);

        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.') {
            answer += c;
        }
    }

    string temp = "";
    for (char c : answer) {
        if (c == '.' && !temp.empty() && temp.back() == '.') {
            continue;
        }
        temp += c;
    }
    answer = temp;
    
    if (!answer.empty() && answer.front() == '.') {
        answer.erase(answer.begin());
    }

    if (!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }

    if (answer.empty()) {
        answer = "a";
    }

    if (answer.length() >= 16) {
        answer = answer.substr(0, 15);

        if (!answer.empty() && answer.back() == '.') {
            answer.pop_back();
        }
    }

    while (answer.length() < 3) {
        answer += answer.back();
    }


    return answer;
}