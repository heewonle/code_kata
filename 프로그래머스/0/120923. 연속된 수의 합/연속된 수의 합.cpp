#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    total -= ((num-1)*num)/2;
    int x  = total/num;
    for(int i=0; i<=num-1; i++){
        answer.push_back(x+i);
    }
    return answer;
}