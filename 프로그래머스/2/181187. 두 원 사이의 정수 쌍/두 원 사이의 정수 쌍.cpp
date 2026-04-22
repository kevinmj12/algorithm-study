#include <string>
#include <vector>
#include <cmath>

using namespace std;

double getD(int x1, int y1, int x2, int y2){
    return pow(pow(y1-y2, 2) + pow(x1-x2, 2), 0.5);
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    int y1 = r1-1;
    int y2 = r2;
    
    for (int x = 0; x < r2; x++){
        while (true){
            if (getD(0, 0, x, y2) <= r2){
                break;
            }
            else{
                y2--;
            }
        }
        while (true){
            if (getD(0, 0, x, y1) < r1 || y1 == 0){
                break;
            }
            else{
                y1--;
            }
        }
        
        answer += (y2 - y1);
    }
    
    
    return answer * 4;
}