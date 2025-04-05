#include <iostream>
#include <algorithm>
using namespace std;
#define NUMBER_MAX 1000000
typedef long long ll;

ll nums[NUMBER_MAX+1];
ll segTree[4*NUMBER_MAX+1];
ll lazy[4*NUMBER_MAX+1];

ll init(int left, int right, int node){
    if (left == right){
        return segTree[node] = nums[left];
    }
    int mid = left + (right - left) / 2;
    return segTree[node] = init(left, mid, node*2) + init(mid+1, right, node*2+1);
}

void updateLazy(int left, int right, int node){
    if (lazy[node] != 0){
        segTree[node] += (right - left + 1) * lazy[node];
        if (left == right){
            return;
        }
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int left, int right, int node, int b, int c, int d){
    updateLazy(left, right, node);
    // 범위 안에 없는 경우
    if (c < left || right < b){
        return;
    }
    // [b, c] 안에 [left, right]가 포함되는 경우 lazy 업데이트
    else if (b <= left && right <= c){
        segTree[node] += (right - left + 1) * d;
        if (left != right){
            lazy[node * 2] += d;
            lazy[node * 2 + 1] += d;
        }
    }
    else{
        int mid = left + (right - left) / 2;
        update(left, mid, node*2, b, c, d);
        update(mid+1, right, node*2+1, b, c, d);
        segTree[node] = segTree[node*2]+segTree[node*2+1];
    }
}

ll sum(int left, int right, int node, int l, int r){
    updateLazy(left, right, node);
    // 범위 안에 없는 경우
    if (r < left || right < l){
        return 0;
    }
    // 범위 안에 있는 경우
    if (l <= left && right <= r){
        return segTree[node];
    }
    // 범위에 걸쳐 있는 경우
    int mid = left + (right - left) / 2;
    return sum(left, mid, node*2, l, r) + sum(mid+1, right, node*2+1, l, r);
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        cin >> nums[i];
    }
    init(1, N, 1);

    for (int i = 1; i <= M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 2){
            ll d;
            cin >> d;
            update(1, N, 1, b, c, d);
            for (int j = b; j <= c; j++){
                nums[j] += d;
            }
        }
        else{
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }  
}