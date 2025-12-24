#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size()==1){
        answer.push_back(-1);
    }
    else{
        int min_value = arr[0];
        int min_index = 0;
        for(int i=0; i<arr.size(); i++){
            if(min_value>arr[i]){
                min_value = arr[i];
                min_index = i;
            }
    }
    arr.erase(min_index+arr.begin());
    answer = arr; 
    }

    return answer;
}