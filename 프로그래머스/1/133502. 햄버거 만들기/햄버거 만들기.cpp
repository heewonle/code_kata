#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> checks ={1,2,3,1};
    for(int i=0; i+3<ingredient.size(); i++){
        bool ham = true;
        for(int j=0; j<4; j++){
            if(checks[j] != ingredient[i+j]){
                ham = false;
                break;
            }
        }
        if(ham==true){
            answer+=1;
            ingredient.erase(ingredient.begin()+i,ingredient.begin()+i+4);
            i = max(i - 4, -1);
        }
    }
    return answer;
}