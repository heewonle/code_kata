#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> baby ={"aya","ye","woo","ma"};

    for(auto word : babbling){
        string before_word ="";
        bool ok = true;
        while(!word.empty()){
            bool matched =false;
            for(int i=0; i<baby.size(); i++){
                string find_word = baby[i];
                auto it = word.find(find_word);
                if (word.rfind(find_word, 0) == 0 && before_word != find_word) {
                    word.erase(0, find_word.size());
                    before_word = find_word;
                    matched = true;
                    break;
                }
            }    
            if(!matched){
                ok =false;
                break;
            }
        }
        if(ok) answer++;
    }
    return answer;
}