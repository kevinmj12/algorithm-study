#include <iostream>
#include <queue>
#include <map>
using namespace std;
map<int, int> m;
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;

void reset(){
    m = map<int, int>();
    maxPQ = priority_queue<int>();
    minPQ = priority_queue<int, vector<int>, greater<int>>();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int k;
        cin >> k;

        reset();
        int elements = 0;
        while (k--){
            char c; int n;
            cin >> c >> n;

            if (c == 'I'){
                elements++;
                m[n]++;
                maxPQ.push(n);
                minPQ.push(n);
            }
            else{
                if (elements > 0){
                    if (n == 1){
                        elements--;
                        while (m[maxPQ.top()] == 0){
                            maxPQ.pop();
                        }
                        m[maxPQ.top()]--;
                        maxPQ.pop();
                    }
                    else {
                        elements--;
                        while (m[minPQ.top()] == 0){
                            minPQ.pop();
                        }
                        m[minPQ.top()]--;
                        minPQ.pop();
                    }
                }   
            }
        }
        // 원소 개수가 0이라면 EMPTY
        if (!elements){
            cout << "EMPTY" << "\n";
        }
        // 이외의 경우 최댓값 최솟값 출력
        else{
            while (m[maxPQ.top()] == 0){
                maxPQ.pop();
            }
            while (m[minPQ.top()] == 0){
                minPQ.pop();
            }
            cout << maxPQ.top() << " " << minPQ.top() << "\n";
        }
    }
}