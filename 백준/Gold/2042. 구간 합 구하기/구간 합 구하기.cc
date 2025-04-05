#include <iostream>
using namespace std;
#define NUMBER_MAX 1000000
typedef long long ll;

ll nums[NUMBER_MAX+1];
ll segTree[4*NUMBER_MAX+1];

ll init(int left, int right, int node){
    if (left == right){
        return segTree[node] = nums[left];
    }
    int mid = left + (right - left) / 2;
    return segTree[node] = init(left, mid, node*2) + init(mid+1, right, node*2+1);
}

void update(int left, int right, int node, int index, ll diff){
    // 범위 안에 없는 경우
    if (index < left || right < index){
        return;
    }
    segTree[node] += diff;
    if (left == right){
        return;
    }
    int mid = left + (right - left) / 2;
    update(left, mid, node*2, index, diff);
    update(mid+1, right, node*2+1, index, diff);
}

ll sum(int left, int right, int node, int l, int r){
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
        if (a == 1){
            ll diff = c-nums[b];
            update(1, N, 1, b, diff);
            nums[b] = c;
        }
        else{
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }  
}
