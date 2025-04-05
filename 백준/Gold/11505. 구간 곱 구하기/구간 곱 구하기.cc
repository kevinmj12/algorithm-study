#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define NUMBER_MAX 1000000
#define MOD 1000000007

ull nums[NUMBER_MAX+1];
ull segTree[NUMBER_MAX*4+1];

ull init(int start, int end, int node){
    if (start == end){
        return segTree[node] = nums[start];
    }
    int mid = start + (end-start)/2;
    ull u = init(start, mid, node*2) * init(mid+1, end, node*2+1);
    u %= MOD;
    return segTree[node] = u;
}

ull sum(int start, int end, int node, int left, int right){
    if (end < left || right < start){
        return 1;
    }
    if (left <= start && end <= right){
        return segTree[node];
    }
    int mid = start + (end-start)/2;
    ull u = sum(start, mid, node*2, left, right) * sum(mid+1, end, node*2+1, left, right);
    u %= MOD;
    return u; 
}

ull update(int start, int end, int node, int index, int val){
    if (index == start && index == end){
        return segTree[node] = val;
    }
    int mid = start + (end-start)/2;
    if (start <= index && index <= mid){
        ull u = (update(start, mid, node*2, index, val) * segTree[node*2+1]);
        u %= MOD;
        return segTree[node] = u;
    }
    else {
        ull u = (segTree[node*2] * update(mid+1, end, node*2+1, index, val)) % MOD;
        u %= MOD;
        return segTree[node] = u;
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    init(1, N, 1);

    for (int i = 1; i <= M+K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1){
            update(1, N, 1, b, c);
        }
        else{
            cout << sum(1, N, 1, b, c) << "\n";
        }
    }
}