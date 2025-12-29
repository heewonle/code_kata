#include <iostream>

using namespace std;

void solution(int n, int m){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    solution(n,m);
}