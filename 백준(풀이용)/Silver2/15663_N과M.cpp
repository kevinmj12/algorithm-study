#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
int nums[8];
vector<vector<int>> s;
set<vector<int>> ss;

void solve(vector<int> v){
    if (v.size() == m){
        s.push_back(v);
        return;
    }
    for (int i = 0; i < n; i++){
        bool isFound = false;
        for (int j = 0; j < v.size(); j++){
            if (v[j] == i) {
                isFound = true;
                break;
            }
        }
        if (!isFound){
            v.push_back(i);
            solve(v);            
            v.pop_back();
        }
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

    solve({});

    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s[i].size(); j++){
            s[i][j] = nums[s[i][j]];
        }
        ss.insert(s[i]);
    }

    for (auto it = ss.begin(); it != ss.end(); it++){
        for (int j = 0; j < m; j++){
            cout << (*it)[j] << " ";
        }
        cout << "\n";
    }
}
