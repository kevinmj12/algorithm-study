#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2001
int soldiers[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> soldiers[i];
        dp[i] = 1;
    }

    int answer = 1;

    for (int i = 2; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (soldiers[j] > soldiers[i]){
                dp[i] = max(dp[i], dp[j]+1);
                answer = max(dp[i], answer);
            }
        }
    }

    cout << N - answer;
}