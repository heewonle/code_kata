#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> sums;
    for(int i=0; i<elements.size(); i++){
        for(int j=1; j<=elements.size(); j++){
            int sum=0;
            for(int k=i; k<i+j; k++){
                if(k>=elements.size()){
                    sum+=elements[k-elements.size()];
                }
                else{
                    sum+=elements[k];
                }  
            }
            sums.insert(sum);
        }
    }
    answer = sums.size();
    return answer;
}