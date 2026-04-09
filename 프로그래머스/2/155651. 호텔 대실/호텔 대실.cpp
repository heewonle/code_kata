#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ToMinute(const string& time){
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> reservations;
    for(const auto& book : book_time){
        int start = ToMinute(book[0]);
        int end = ToMinute(book[1]) + 10;
        reservations.push_back({start,end});
    }
    sort(reservations.begin(),reservations.end());
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(const auto& reservation : reservations){
        int start = reservation.first;
        int end = reservation.second;
        if(!minHeap.empty() && minHeap.top()<=start){
            minHeap.pop();
        }
        minHeap.push(end);
    }
    answer =  (int)minHeap.size();
    return answer;
}