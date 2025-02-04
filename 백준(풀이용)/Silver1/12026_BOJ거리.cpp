#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 1001
char blocks[MAX];
bool canMove[MAX];
int dp[MAX];

char previousBlock(char c){
    if (c == 'B'){
        return 'J';
    }
    else if (c == 'O'){
        return 'B';
    }
    else{
        return 'O';
    }
}

int main(){
    int N;
    cin >> N;

    string input;
    cin >> input;

    for (int i = 1; i <= N; i++){
        blocks[i] = input[i-1];
        canMove[i] = false;
        dp[i] = INT_MAX;
    }

    // base case
    canMove[1] = true;
    dp[1] = 0;

    // dp
    for (int i = 2; i <= N; i++){
        char block = blocks[i];
        char pb = previousBlock(block);

        for (int j = 1; j < i; j++){
            if (canMove[j] && blocks[j] == pb){
                canMove[i] = true;
                dp[i] = min(dp[i], dp[j] + (i-j)*(i-j));
            }
        }
    }

    if (canMove[N]){
        cout << dp[N];
    }
    else{
        cout << -1;
    }
}