#include <iostream>
using namespace std;

int dissolutionSum(int n){
    int answer = n;
    while (n > 0){
        answer += n % 10;
        n /= 10;
    }
    return answer;
}

void solve(int n){
    int answer = 1;
    while (answer < n){
        int k = dissolutionSum(answer);
        if (k == n){
            printf("%d", answer);
            return;
        }
        answer++;
    }
    printf("0");
    return;
}

int main(){
    int n;
    scanf("%d", &n);

    solve(n);
}