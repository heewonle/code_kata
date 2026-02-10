#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown +  yellow;
    for(int i=1; i<=1000000; i++){
        int n=i;
        if(sum%n==0){
            int m = sum/n;
            if((2*n+2*m-4)==brown){
                if(m>=n){
                    answer.push_back(m);
                    answer.push_back(n);
                }
                else{
                    answer.push_back(n);
                    answer.push_back(m);
                }
                break;
            }
        }
    }

    return answer;
}