#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_w=0;
    int max_h=0;
    for(int i=0; i<sizes.size(); i++){
        int max_size = max(sizes[i][0],sizes[i][1]);
        int min_size = min(sizes[i][0],sizes[i][1]);
        max_w = max(max_size, max_w);
        max_h = max(min_size, max_h);
    }
    answer = max_w * max_h;
    return answer;
}