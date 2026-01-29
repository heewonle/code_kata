#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> ys;
    vector<int> xs;
    for(int y=0; y<wallpaper.size(); y++){
        string temp = wallpaper[y];
        for(int x=0; x<temp.length(); x++){
            if(temp[x]=='#'){
                xs.push_back(x);
                ys.push_back(y);
            }
        } 
    }
    int min_x = *min_element(xs.begin(),xs.end());
    int max_x = *max_element(xs.begin(),xs.end());
    int min_y = *min_element(ys.begin(),ys.end());
    int max_y = *max_element(ys.begin(),ys.end());
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y+1);
    answer.push_back(max_x+1);
    return answer;
}