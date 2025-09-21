#include <iostream>
using namespace std;
#define MAX 100000
#define NUM_MAX 1000000000


int N, M;
int nums[MAX+1];
int segTree[4*MAX+1];

int init(int left, int right, int index){
    if (left == right){
        return segTree[index] = left;
    }
    int mid = left + (right-left)/2;

    int leftValue = init(left, mid, index*2);
    int rightValue = init(mid+1, right, index*2+1);
    
    if (nums[leftValue] <= nums[rightValue]){
        return segTree[index] = leftValue;
    }
    else{
        return segTree[index] = rightValue;
    }
}

int find(int left, int right, int l, int r, int index){
    if (r < left || right < l){
        return 0;
    }
    if (l <= left && right <= r){
        return segTree[index];
    }
    int mid = left + (right-left)/2;

    int leftValue = find(left, mid, l, r, index*2);
    int rightValue = find(mid+1, right, l, r, index*2+1);

    if (nums[leftValue] <= nums[rightValue]){
        return leftValue;
    }
    else{
        return rightValue;
    }
}

int update(int left, int right, int target, int index){
    if (target < left || right < target){
        return segTree[index];
    }
    if (left == right){
        return segTree[index];
    }
    int mid = left + (right-left)/2;

    
    int leftValue = update(left, mid, target, index*2);
    int rightValue = update(mid+1, right, target, index*2+1);

    if (nums[leftValue] <= nums[rightValue]){
        return segTree[index] = leftValue;
    }
    else{
        return segTree[index] = rightValue;
    }
}

void command1(int a, int b){
    nums[a] = b;
    update(1, N, a, 1);
}

void command2(int a, int b){
    int answer = find(1, N, a, b, 1);
    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> nums[i];
    }
    nums[0] = NUM_MAX+1;
    init(1, N, 1);

    cin >> M;
    for (int i = 1; i <= M; i++){
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1){
            command1(a, b);
        }
        else{
            command2(a, b);
        }
    }
}