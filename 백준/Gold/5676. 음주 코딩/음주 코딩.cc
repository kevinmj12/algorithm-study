#include <iostream>
using namespace std;
#define NUMBER_MAX 100000

int nums[NUMBER_MAX+1];
int segTree[NUMBER_MAX*4+1];

int init(int start, int end, int node){
    if (start == end){
        return segTree[node] = nums[start];
    }
    int mid = start + (end-start)/2;
    return segTree[node] = init(start, mid, node*2)*init(mid+1, end, node*2+1);
}

int update(int start, int end, int node, int index, int val){
    if (index < start || end < index){
        return segTree[node];
    }
    if (index == start && index == end){
        return segTree[node] = val;
    }
    int mid = start + (end-start)/2;
    return segTree[node] = update(start, mid, node*2, index, val)*update(mid+1, end, node*2+1, index, val);
}

int sum(int start, int end, int node, int left, int right){
    if (right < start || end < left){
        return 1;
    }
    if (left <= start && end <= right){
        return segTree[node];
    }
    int mid = start + (end-start)/2;
    return sum(start, mid, node*2, left, right)*sum(mid+1, end, node*2+1, left, right);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;

    while (cin >> N >> K) {
        for (int i = 1; i <= N; i++){
            cin >> nums[i];
            if (nums[i] > 0){
                nums[i] = 1;
            }
            else if (nums[i] < 0){
                nums[i] = -1;
            }
        }

        init(1, N, 1);
        
        for (int i = 1; i <= K; i++){
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'C'){
                if (c > 0){
                    c = 1;
                }
                else if (c < 0){
                    c = -1;
                }
                
                if (nums[b] * c <= 0){
                    update(1, N, 1, b, c);
                    nums[b] = c;
                }
            }
            else{
                int val = sum(1, N, 1, b, c);
                if (val > 0){
                    cout << "+";
                }
                else if (val == 0){
                    cout << "0";
                }
                else{
                    cout << "-";
                }
            }
        }
        cout << "\n";
    }
}