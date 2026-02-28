#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    for(int i=1; i<n; i++){
        if(n%i==1 && i<answer){
            answer = i;
        }
    }
    return answer;
}