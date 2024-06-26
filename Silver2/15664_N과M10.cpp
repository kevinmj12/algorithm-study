#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int nums[8];
set<vector<int>> answer;

void printAnswer(){
    for (auto it = answer.begin(); it != answer.end(); it++){
        for (int i = 0; i < (*it).size(); i++){
            cout << (*it)[i] << " ";
        }
        cout << "\n";
    }
}

void solve(vector<int> v, int start){
    if (v.size() == m){
        answer.insert(v);
        return;
    }
    for (int i = start; i < n; i++){
        v.push_back(nums[i]);
        solve(v, i+1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums, nums+n);

    solve({}, 0);
    printAnswer();
}