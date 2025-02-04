#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000
int nums[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;

    for (int i = 0; i < 2; i++){
        int n;
        cin >> n;

        pq1.push(n);
        cout << pq1.top() << "\n";
    }
    for (int i = 2; i < N; i++){
        if (i % 2 == 0){
            pq2.push(pq1.top());
            pq1.pop();
        }
        int n;
        cin >> n;

        pq1.push(n);
        if (pq1.top() < pq2.top()){
            pq1.push(pq2.top());
            pq2.push(pq1.top());
            pq1.pop();
            pq2.pop();
        }
        cout << pq1.top() << "\n";
    }
}