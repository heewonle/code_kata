#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> nums;
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<numbers.size(); j++){
            if(i!=j){
                int num = numbers[j]+numbers[i];
                nums.insert(num);  
            }

        }
    }
    for(auto& num : nums){
        answer.push_back(num);
    }
    sort(answer.begin(),answer.end());
    return answer;
}