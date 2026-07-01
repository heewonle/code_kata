#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int max_health = health;
    int max_t = attacks[attacks.size() - 1][0];
    
    unordered_map<int, int> checks;
    checks.reserve(max_t);
    for(auto i : attacks){
        checks[i[0]] = i[1];
    }
    
    int check = 0;
    for(int i = 1; i <= max_t; i++){        
        if(checks.count(i) > 0 && checks[i] != 0){
            health -= checks[i];
            check = 0; 
            
            if(health <= 0) return -1;
        }
        else { 
            check += 1;
            health += bandage[1]; 
            
            if(check == bandage[0]) { 
                health += bandage[2];
                check = 0;
            }
            health = min(health, max_health);
        }
    }
    
    return health;
}