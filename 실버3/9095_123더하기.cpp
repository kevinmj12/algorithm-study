#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> dp;
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);

    int tCase;
    cin >> tCase;

    while (tCase--){
        int n;
        cin >> n;

        int s = dp.size();
        if (n <= s){
            cout << dp[n-1] << "\n";
        }
        else{
            while(s < n){
                dp.push_back(dp[s-1]+dp[s-2]+dp[s-3]);
                s++;
            }
            cout << dp[s-1] << "\n";
        }
        

    }
}