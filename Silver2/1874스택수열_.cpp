#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    stack<int> num;
    queue<bool> answer;

    int maxNum = 0;
    for (int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        if (k > maxNum){
            while (k > maxNum){
                maxNum++;
                num.push(maxNum);
                answer.push(1);
            }
            num.pop();
            answer.push(0);
        }
        else if (k == num.top()){
            num.pop();
            answer.push(0);
        }
        else{
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < 2*n; i++){
        bool b = answer.front();
        if (b) {printf("+\n");}
        else {printf("-\n");}
        answer.pop();
    }
}