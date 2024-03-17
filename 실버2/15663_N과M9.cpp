#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int nums[8];

void solve(int start, int length, vector<int> v){
    if (length > m){
        for (int i = 0; i < m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < n; i++){
        v.push_back(nums[i]);
        solve(i, length+1, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums+n);

    solve(0, 1, {});
}