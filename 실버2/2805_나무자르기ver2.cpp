#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_HEIGHT 1000000000
int n, m;
int trees[1000000];
int answer = 0;

void solve(int left, int right){
    if (left > right){
        return;
    }
    int mid = (left+right)/2;
    long long total = 0;
    for (int i = 0; i < n; i++){
        if (trees[i] > mid){
            total += trees[i]-mid;
        }
    }
    if (total < m){
        solve(left, mid-1);
    }
    else{
        answer = max(answer, mid);
        solve(mid+1, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> trees[i];
    }
    
    solve(0, MAX_HEIGHT);

    cout << answer;
}