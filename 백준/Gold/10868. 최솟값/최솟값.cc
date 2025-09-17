#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
#define NUM_MAX 1000000001

int nums[MAX+1];
int segTree[4*MAX+1];

int init(int left, int right, int node){
    if (left == right){
        return segTree[node] = nums[left];
    }
    int mid = left + (right - left) / 2;
    return segTree[node] = min(init(left, mid, node*2), init(mid+1, right, node*2+1));
}

int findMin(int left, int right, int node, int l, int r){
    if (r < left || right < l){
        return NUM_MAX;
    }
    if (l <= left && right <= r){
        return segTree[node];
    }

    int mid = left + (right - left) / 2;
    return min(findMin(left, mid, node*2, l, r), findMin(mid+1, right, node*2+1, l, r));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    init(1, N, 1);

    for (int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;

        cout << findMin(1, N, 1, a, b) << "\n";

    }
}