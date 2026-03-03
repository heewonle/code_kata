#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> nums(number+1,0);
    for (int i = 1; i <= number; i++) {
        for (int j = i; j <= number; j += i) {
            nums[j]++;
        }
    }

    for (int i = 1; i <= number; i++) {
        if (nums[i] > limit)
            nums[i] = power;
        answer += nums[i];
    }

    return answer;
}