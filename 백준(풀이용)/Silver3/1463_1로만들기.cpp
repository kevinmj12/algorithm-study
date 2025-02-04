#include <iostream>
#include <queue>
using namespace std;

void solve(int n){
    if (n == 1){
        printf("0");
        return;
    }
    queue<int> order;
    int answer = 0;
    order.push(n);
    while (!order.empty()){
        answer++;
        int tmpSize = order.size();
        while (tmpSize--){
            int tmp = order.front();
            if (tmp%3 ==0){
                if (tmp == 3){
                    printf("%d", answer);
                    return;
                }
                order.push(tmp / 3);
            }
            if (tmp%2 == 0){
                if (tmp == 2){
                    printf("%d", answer);
                    return;
                }
                order.push(tmp / 2);
            }
            order.push(tmp - 1);
            order.pop();
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    solve(n);
}