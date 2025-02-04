#include <iostream>
#include <algorithm>
using namespace std;

int rooms[1000001];
void init(int n){
    for (int i = 1; i <= n; i++){
        rooms[i] = i;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    init(n);
    for (int i = 0; i < m; i++){
        int left, right;
        cin >> left >> right;

        rooms[left] = right;
    }

    int answer = 0;
    int cur = 1;
    while (cur <= n){
        answer++;
        if (rooms[cur] != cur){
            int next = rooms[cur];
            int tmp = cur+1;
            while (tmp <= next){
                next = max(rooms[tmp], next);
                tmp++;
            }
            cur = next;
        }
        cur++;
    }

    cout << answer;
}