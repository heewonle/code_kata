#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int j=1; j<arr.size(); j++){
        int l = gcd(answer, arr[j]);
        int lcm = answer * arr[j] / l;
        answer = lcm;
    }
    return answer;
}