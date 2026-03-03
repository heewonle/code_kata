#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int best_correct = 0;
    int worst_correct = 0;
    unordered_map<int,int> correct = {{0,6},{1,6},{2,5},{3,4},{4,3},{5,2},{6,1}};
    for(int i=0; i<win_nums.size(); i++){
        auto it = find(lottos.begin(),lottos.end(),win_nums[i]);
        if(it!=lottos.end()){
            best_correct++;
            worst_correct++;
        }
    }
    int num_zero = count(lottos.begin(),lottos.end(),0);
    for(int i=0; i<num_zero; i++){
        best_correct++;
        
    }
    answer.push_back(correct[best_correct]);
    answer.push_back(correct[worst_correct]);
    return answer;
}