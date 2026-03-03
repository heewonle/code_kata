#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    set<set<int>> check_list;
    for(int i=0; i<number.size(); i++){
        for(int j=0; j<number.size(); j++){
            for(int k=0; k<number.size(); k++){
                set<int> check;
                if(i!=j && i!=k && j!=k){
                    int sum = number[i] + number[j] + number[k];
                    if(sum==0){
                        check.insert(i);
                        check.insert(j);
                        check.insert(k);
                        check_list.insert(check);
                    }
                }
            }
        }
    }
    answer = check_list.size();
    return answer;
}