#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPelindrome(int start, int end, string str){
    while (start <= end){
        if (str[start] == str[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cin >> str;

    int len = str.length();
    // pelindrome[i]에 str[i]를 마지막으로 하는 모든 팰린드롬 길이를 저장
    vector<int> pelindrome[len];
    for (int i = 0; i <= len-1; i++){
        int j = 0;
        while (j <= i){
            if (isPelindrome(j, i, str)){
                pelindrome[i].push_back(i-j+1);
            }
            j++;
        }
        
    }

    // dp[i] 에 str[i]까지의 팰린드롬 분할의 최솟값을 저장
    int dp[len];
    dp[0] = 1;

    for (int i = 1; i < len; i++){
        dp[i] = dp[i-1]+1;

        for (int j = 0; j < pelindrome[i].size(); j++){
            // 문자열 자체가 팰린드롬일때
            if (pelindrome[i][j]-1 == i){
                dp[i] = 1;
            }
            // 이외의 경우
            else{
                dp[i] = min(dp[i], dp[i-pelindrome[i][j]]+1);
            }
        }
    }

    cout << dp[len-1];
}