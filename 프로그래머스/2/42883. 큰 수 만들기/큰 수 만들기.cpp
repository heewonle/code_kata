#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer.reserve(number.size());

    for (char c : number) {
        while (!answer.empty() && k > 0 && answer.back() < c) {
            answer.pop_back();
            --k;
        }
        answer.push_back(c);
    }
    while (k > 0) {
        answer.pop_back();
        --k;
    }
    
    return answer;
}