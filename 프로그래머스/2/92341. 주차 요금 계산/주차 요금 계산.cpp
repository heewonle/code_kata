#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
using namespace std;
int timeToMin(string time){
    int h,m;
    sscanf(time.c_str(), "%d:%d",&h,&m);
    return h*60 + m;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> car_tr;
    map<string,pair<string,string>> car_times;
    for(auto s : records){
        string car_num = s.substr(6,4);
        car_tr[car_num] = 0;
    }
    for(auto s : records){
        string time = s.substr(0,5);
        string car_num = s.substr(6,4);
        string re = s.substr(11);
        if(re=="IN"){
            car_times[car_num] = make_pair(time,"23:59");
        }
        else if(re=="OUT"){
            car_times[car_num].second = time;
            int time = timeToMin(car_times[car_num].second) - timeToMin(car_times[car_num].first);
            car_tr[car_num] += time;
            car_times.erase(car_num);
        }
    }
    for(auto k : car_times){
            int time = timeToMin(car_times[k.first].second) - timeToMin(car_times[k.first].first);
            car_tr[k.first] += time;
    }
    for(auto k : car_tr){
            int time = k.second;
            int price;
            if(time<=fees[0]){
                price = fees[1];
            }
            else{
                price = fees[1] +ceil((time - fees[0])/(float)fees[2])* fees[3];
            }
            answer.push_back(price);
    }
    return answer;
}