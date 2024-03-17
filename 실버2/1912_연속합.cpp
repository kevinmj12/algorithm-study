
// Kadane algorithm
// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int answer = -1000;
//     int sum = 0;
//     while (n--){
//         int num;
//         cin >> num;
//         sum += num;

//         if (sum > answer){
//             answer = sum;
//         }

//         if (sum < 0){
//             sum = 0;
//         }
//     }
//     cout << answer;
// }

// DP
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int dp[MAX];

int main(){
    int n;
    cin >> n;

    dp[0] = -1000;
    int answer = -1000;

    for (int i = 1; i <= n; i++){
        int num;
        cin >> num;
        dp[i] = max(dp[i-1]+num, num);
        answer = max(answer, dp[i]);
    }

    cout << answer;
}