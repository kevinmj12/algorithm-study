#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> lh;
    
    int N;
    scanf("%d", &N);

    while (N--){
        int x;
        scanf("%d", &x);

        // 배열에서 가장 작은값 출력 후 배열 제거
        if (x == 0){
            if (lh.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", lh.top());
                lh.pop();
            }
        }
        // 배열에 x값 추가
        else{
            lh.push(x);
        }
    }
}