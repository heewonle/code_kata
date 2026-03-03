#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int n = (int)s.size();
    int i = 0;

    while (i < n) {
        char x = s[i];
        int eq = 1;      
        int uneq = 0;
        int j = i + 1;

        while (j < n && eq != uneq) {
            if (s[j] == x) eq++;
            else uneq++;
            j++;
        }

        answer++;    
        i = j;       
    }
    return answer;
}