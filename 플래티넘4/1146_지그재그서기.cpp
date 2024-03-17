#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000
int n;
int dp[100][100];
//왼쪽에 left개, 오른쪽에 right개의 숫자가 있을 때의 경우의 수
int solve(int left, int right){
	int here = n- (left + right);
	if(here == n) return 1;
	int &ret = dp[left][right];
	if(ret != -1) return ret;

	ret = 0;
	if(right == 0) return ret;
	for(int i=0; i<right; ++i)
		ret = (ret + solve(right-1-i, left+i))%MOD;
	return ret;
}
int main(){
	cin >> n;

	if (n==1){
		cout << 1;
		return 0;
	}

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
    
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = (ans + solve(i, n-i-1))%MOD;
		ans = (ans + solve(n-i-1, i))%MOD;
	}
	cout << ans;
}