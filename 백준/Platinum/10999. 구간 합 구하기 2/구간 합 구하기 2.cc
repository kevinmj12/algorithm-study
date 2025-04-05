#include <iostream>
#include <algorithm>
using namespace std;
#define NUMBER_MAX 1000000
typedef long long ll;

ll nums[NUMBER_MAX+1];
ll segTree[4*NUMBER_MAX+1];
ll lazy[4*NUMBER_MAX+1];

ll init(int start, int end, int node){
    if (start == end){
        return segTree[node] = nums[start];
    }
    int mid = start + (end - start) / 2;
    return segTree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

void updateLazy(int start, int end, int node){
    if (lazy[node] != 0){
        segTree[node] += (end - start + 1) * lazy[node];
        if (start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int b, int c, long long d){
    updateLazy(start, end, node);
    // 범위 안에 없는 경우
    if (c < start || end < b){
        return;
    }
    // [b, c] 안에 [start, end]가 포함되는 경우 lazy 업데이트
    else if (b <= start && end <= c){
        segTree[node] += (end - start + 1) * d;
        if (start != end){
            lazy[node*2] += d;
            lazy[node*2+1] += d;
        }
        return;
    }
    else{
        int mid = start + (end - start) / 2;
        update(start, mid, node*2, b, c, d);
        update(mid+1, end, node*2+1, b, c, d);
        segTree[node] = segTree[node*2]+segTree[node*2+1];
    }
}

ll sum(int start, int end, int node, int left, int right){
    updateLazy(start, end, node);
    // 범위 안에 없는 경우
    if (right < start || end < left){
        return 0;
    }
    // 범위 안에 있는 경우
    if (left <= start && end <= right){
        return segTree[node];
    }
    // 범위에 걸쳐 있는 경우
    int mid = start + (end - start) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
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
        if (a == 1){
            ll d;
            cin >> d;
            update(1, N, 1, b, c, d);
        }
        else{
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }  
}