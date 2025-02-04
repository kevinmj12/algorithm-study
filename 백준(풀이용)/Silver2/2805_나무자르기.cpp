#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001
long long trees[MAX];

int solve(long long left, long long right, int n, int m){
    int answer;
    while (left <= right){
        long long mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++){
            if (trees[i] > mid){
                total += trees[i] - mid;
            }
        }
        if (total >= m){
            answer = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int maxH = 0;
    for (int i = 0; i < n; i++){
        cin >> trees[i];
    }

    sort(trees, trees+n);
    
    cout << solve(0, 1000000000, n, m);
}