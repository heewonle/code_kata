#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(int a, int b) {
    map<int,string> ans_map = {{0,"FRI"},{1,"SAT"},{2,"SUN"},{3,"MON"},{4,"TUE"},{5,"WED"},{6,"THU"}};
    string answer = "";
    int days[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int count_day = 0;
    for(int i=0;i<a-1;i++) count_day += days[i];
    count_day += b-1;
    int ans_num = count_day%7;
    answer = ans_map[ans_num];
    return answer;
}