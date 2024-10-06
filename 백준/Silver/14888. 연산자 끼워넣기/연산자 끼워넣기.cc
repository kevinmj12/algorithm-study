#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int nums[12];
int cals[4];
int maxNum = INT_MIN;
int minNum = INT_MAX;

void solve(int a, int idx){
    if (idx == n){
        maxNum = max(maxNum, a);
        minNum = min(minNum, a);
        return;
    }
    if (cals[0]){
        cals[0]--;
        solve(a+nums[idx], idx+1);
        cals[0]++;
    }
    if (cals[1]){
        cals[1]--;
        solve(a-nums[idx], idx+1);
        cals[1]++;
    }
    if (cals[2]){
        cals[2]--;
        solve(a*nums[idx], idx+1);
        cals[2]++;
    }
    if (cals[3]){
        cals[3]--;
        solve(a/nums[idx], idx+1);
        cals[3]++;;
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> cals[i];
    }

    solve(nums[0], 1);

    cout << maxNum << "\n";
    cout << minNum;
}