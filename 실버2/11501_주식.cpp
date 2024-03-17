#include <iostream>
using namespace std;
int prices[1000001];

long long solve(int n){
    // 마지막날부터 이동하면서 제일 비싼 가격을 저장
    int maxPrice = prices[n-1];
    long long answer = 0;
    for (int i = n-2; i >= 0; i--){
        // 전날 가격이 더 높거나 같은 경우는 살 필요가 없음
        if (prices[i] >= maxPrice){
            maxPrice = prices[i];
        }
        // 전날 가격이 더 낮다면 판매
        else {
            answer += (maxPrice - prices[i]);
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        for (int i = 0; i < n; i++){
            cin >> prices[i];
        }

        cout << solve(n) << "\n";
    }
}