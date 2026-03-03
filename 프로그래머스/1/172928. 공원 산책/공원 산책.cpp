#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int x = 0, y = 0;

    for (int j = 0; j < (int)park.size(); j++) {
        for (int k = 0; k < (int)park[j].size(); k++) {
            if (park[j][k] == 'S') { x = k; y = j; }
        }
    }

    for (int i = 0; i < (int)routes.size(); i++) {
        string direction = routes[i].substr(0, 1);
        int length = stoi(routes[i].substr(2)); 

        int stepX = 0, stepY = 0;
        if (direction == "N") stepY = -1;
        else if (direction == "S") stepY = 1;
        else if (direction == "W") stepX = -1;
        else if (direction == "E") stepX = 1;

        bool can = true;
        int nx = x, ny = y;

        for (int s = 0; s < length; s++) {
            nx += stepX;
            ny += stepY;

            if (ny < 0 || nx < 0 || ny >= (int)park.size() || nx >= (int)park[0].size()) {
                can = false;
                break;
            }
            if (park[ny][nx] == 'X') {
                can = false;
                break;
            }
        }

        if (can) { x = nx; y = ny; }
    }

    return { y, x };
}
