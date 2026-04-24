#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int getDistance(int x1, int y1, int x2, int y2){
    int yd = abs(y2-y1);
    int xd = abs(x2-x1);
    return yd*yd + xd*xd;
}

int gcd(int a, int b){
    if (a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

bool isOnOne(int x1, int y1, int x2, int y2, int x3, int y3){
    int dx1 = x3-x1;
    int dy1 = y3-y1;
    int dx2 = x3-x2;
    int dy2 = y3-y2;
    
    int gcd1 = gcd(dx1, dy1);
    int gcd2 = gcd(dx2, dy2);
    if (dx1/gcd1 == dx2/gcd2 && dy1/gcd1 == dy2/gcd2){
        return true;
    }
    return false;
}


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (int i = 0; i < balls.size(); i++){
        int ballX = balls[i][0];
        int ballY = balls[i][1];
        
        int movedBalls[4][2] = {{-ballX, ballY}, {m+(m-ballX), ballY},
                                {ballX, -ballY}, {ballX, n+(n-ballY)}};
        
        int minDistance = INT_MAX;
        for (int i = 0; i < 4; i++){
            int d = getDistance(
                startX, startY, movedBalls[i][0], movedBalls[i][1]);
            
            if (i == 0 && startY == ballY && startX > ballX){
                continue;
            }
            else if (i == 1 && startY == ballY && startX < ballX){
                continue;
            }
            else if (i == 2 && startX == ballX && startY > ballY){
                continue;
            }
            else if (i == 3 && startX == ballX && startY < ballY){
                continue;
            }
            minDistance = min(minDistance, d);
        }
        // 모서리
        int corners[4][2] = {{0, 0}, {m, 0}, {0, n}, {m, n}};
        int nBalls[4][2] = {{-ballX, -ballY}, {m+(m-ballX), -ballY},
                            {-ballX, n+(n-ballY)}, {m+(m-ballX), n+(n-ballY)}};
        
        if (isOnOne(startX, startY, ballX, ballY, 0, 0)){
            int d;
            if (startX < ballX){
                d = getDistance(startX, startY, -ballX, -ballY);
            }
            else{
                d = getDistance(startX, startY, m+(m-ballX), n+(n-ballY));
            }
            minDistance = min(minDistance, d);
        }
        else if (isOnOne(startX, startY, ballX, ballY, m, 0)){
            int d;
            if (startX < ballX){
                d = getDistance(startX, startY, -ballX, n+(n-ballY));
            }
            else{
                d = getDistance(startX, startY, m+(m-ballX), -ballY);
            }
            minDistance = min(minDistance, d);
        }
        
        
        answer.push_back(minDistance);
    }
    
    return answer;
}