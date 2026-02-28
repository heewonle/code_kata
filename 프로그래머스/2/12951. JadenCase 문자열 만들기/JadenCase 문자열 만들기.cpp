#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer;
    answer.reserve(s.size());
    bool newWord = true; 
    for (unsigned char uc : s) {
        char c = (char)uc;
        if (c == ' ') {       
            answer += c;
            newWord = true;      
        } else {
            if (newWord) {
                answer += (char)toupper(uc);
                newWord = false;
            } else {
                answer += (char)tolower(uc);
            }
        }
    }

    return answer;
}