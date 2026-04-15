#include <vector>
#include <algorithm>
using namespace std;

int getGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int findValidGCD(const vector<int>& target, const vector<int>& other)
{
    int gcdValue = target[0];
    for (int i = 1; i < target.size(); i++)
    {
        gcdValue = getGCD(gcdValue, target[i]);
    }

    for (int num : other)
    {
        if (num % gcdValue == 0)
        {
            return 0;
        }
    }

    return gcdValue;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
        int candidateA = findValidGCD(arrayA, arrayB);
    int candidateB = findValidGCD(arrayB, arrayA);

    answer = max(candidateA, candidateB);
    return answer;
}