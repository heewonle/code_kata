#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> sv;
    string temp = "";
    for(int i=0; i<s.length(); i++){
        temp +=s[i];
        if(s[i]==' ' || i==(s.length()-1)){
            sv.push_back(temp); 
            temp = "";
        }
    }

    for(int v=0; v<sv.size(); v++){
        for(int i=0; i<sv[v].length(); i++){
            if(i%2==0){
                answer+=toupper(sv[v][i]);
            }
            else{
                answer+=tolower(sv[v][i]);
            }
        }
    }
    return answer;
}