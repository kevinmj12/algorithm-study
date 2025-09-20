#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int heights[100001];

ull solve(int left, int right){
    if (left == right){
        return heights[left];
    }
    int mid = left + (right - left) / 2;
    
    ull leftMax = solve(left, mid);
    ull rightMax = solve(mid+1, right);

    // 경계점을 기준으로 좌우로 넓혀가며 면적 계산해보기
    int l = mid;
    int r = mid+1;
    int minH = min(heights[l], heights[r]);
    ull middleMax = 2 * minH;
    while (left <= l && r <= right){
        minH = min(min(heights[l], heights[r]), minH);
        middleMax = max(middleMax, ull(r-l+1)*minH);

        int ll = 0, rr = 0;
        if (left <= l-1){
            ll = heights[l-1];
        }
        if (r+1 <= right){
            rr = heights[r+1];
        }

        if (ll == 0 && rr == 0){
            break;
        }
        else if (ll < rr){
            r++;
        }
        else{
            l--;
        }
    }

    return max(max(leftMax, rightMax), middleMax);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    while (true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }

        for (int i = 1; i <= n; i++){
            cin >> heights[i];
        }

        ull answer = solve(1, n);
        cout << answer << "\n";
    }
}