#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int apps[101][2];
int dp[101][10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
	cin >> n >> m;

    // 메모리를 입력받음
	for (int i = 1; i <= n; i++){
        cin >> apps[i][0];
    }
    // 비용을 입력받으면서 비용의 총합을 저장
    int totalCost = 0;
	for (int i = 1; i <= n; i++) {
		cin >> apps[i][1];
		totalCost += apps[i][1];
	}

	for (int i = 1; i <= n; i++){
        for (int j = 0; j < apps[i][1]; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
		for (int j = apps[i][1]; j <= totalCost; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j - apps[i][1]] + apps[i][0]);
		}
	}

	for (int i = 0; i <= totalCost; i++){
		if (dp[n][i] >= m){
			cout << i;
			return 0;
		}	
	}
}