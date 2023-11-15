#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;

int moveZ(int n, int y, int x){
    // printf("%d %d %d\n", n, y, x);
    if (n == 1){
        return 0;
    }
    else{
        // Z의 이동경로를 1, 2, 3, 4라 하자.
        // 1번에 해당
        if (r < n/2+y && c < n/2+x){
            return moveZ(n/2, y, x);
        }
        // 2번에 해당
        else if (r < n/2+y && c >= n/2+x){
            return (n/2 * n/2) + moveZ(n/2, y, n/2+x);
        }
        // 3번에 해당
        else if (r >= n/2+y && c < n/2+x){
            return 2 * (n/2 * n/2) + moveZ(n/2, n/2+y, x);
        }
        // 4번에 해당
        else{
            return 3 * (n/2 * n/2) + moveZ(n/2, n/2+y, n/2+x);    
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &r, &c);
    
    printf("%d", moveZ(pow(2, N), 0, 0));
}