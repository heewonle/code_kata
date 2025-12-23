#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    answer = num1* 1000/num2;
    cout << answer << endl;
    return answer;
}