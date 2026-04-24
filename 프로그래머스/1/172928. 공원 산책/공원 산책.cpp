#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int sy = 0;
    int sx = 0;
    
    for (int i = 0; i < park.size(); i++){
        for (int j = 0; j < park[0].length(); j++){
            if (park[i][j] == 'S'){
                sy = i;
                sx = j;
                park[i][j] = 'O';
                break;
            }
        }
    }
    
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int curY = sy;
    int curX = sx;
    
    for (int i = 0; i < routes.size(); i++){
        char op = routes[i][0];
        int n = routes[i][2] - '0';
        
        int d;
        if (op == 'E') d = 0;
        else if (op == 'W') d = 1;
        else if (op == 'S') d = 2;
        else d = 3;
        
        int nextY = curY;
        int nextX = curX;
        bool canMove = true;
        for (int j = 0; j < n; j++){
            if (nextY+dirs[d][0] < 0 || nextY+dirs[d][0] >= park.size() ||
               nextX+dirs[d][1] < 0 || nextX+dirs[d][1] >= park[0].size() ||
               park[nextY+dirs[d][0]][nextX+dirs[d][1]] == 'X'){
                canMove = false;
                break;
            }
            nextY += dirs[d][0];
            nextX += dirs[d][1];
        }
                
        if (canMove){
            curY = nextY;
            curX = nextX;
        }
    }
    
    answer = {curY, curX};
    
    return answer;
}