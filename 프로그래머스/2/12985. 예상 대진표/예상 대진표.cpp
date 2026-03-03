#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int count = 1;
    int max_num = max(a,b);
    int min_num = min(a,b);
    while (!((max_num % 2 == 0 && min_num == max_num - 1) ||
             (max_num % 2 == 1 && min_num == max_num + 1))){
        if(min_num%2>=1){
            min_num=min_num/2+1;
        }
        else{
            min_num=min_num/2;
        }
        if(max_num%2>=1){
            max_num=max_num/2+1;
        }
        else{
            max_num=max_num/2;
        }
        count+=1;     
    }
    answer=count;
    return answer;
}