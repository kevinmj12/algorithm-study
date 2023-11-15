#include <iostream>
#include <climits>
using namespace std;
#define MAX 502
int matrixSizeArr[MAX];
int dp[MAX][MAX];
// int order[MAX][MAX];

// void printOrder(int i, int j){
//     if (i == j){
//         cout << "M" << i;
//     }
//     else{
//         int k = order[j][i];
//         cout << "(";
//         printOrder(i, k);
//         printOrder(k+1, j);
//         cout << ")"; 
//     }
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int numMatrix;
    cin >> numMatrix;
    for (int i = 0; i < numMatrix; i++){
        cin >> matrixSizeArr[i] >> matrixSizeArr[i+1];
    }

    for (int i = 1; i <= numMatrix; i++){
        dp[i][i] = 0;
        for (int j = i-1; j >= 1; j--){
            int minVal = INT_MAX;
            int minK;
            for (int k = j; k < i; k++){
                int val = dp[k][j]+dp[i][k+1]+matrixSizeArr[j-1]*matrixSizeArr[k]*matrixSizeArr[i];
                if (val < minVal){
                    minVal = val;
                    minK = k;
                }
            }
            dp[i][j] = minVal;
            // order[i][j] = minK;
        }
    }

    // printOrder(1, numMatrix);
    // cout << "\n";
    cout << dp[numMatrix][1] << "\n";

}