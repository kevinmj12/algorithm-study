#include <iostream>
#include <algorithm>
using namespace std;

int gates[100001];
int gateRoot[100001];

int findRoot(int x){
    if (gateRoot[x] == x){
        return x;
    }
    else if (x == 1){
        return -1;
    }
    else{
        return gateRoot[x] = findRoot(gateRoot[x]);
    }
}

int main(){
    int g, p;
    cin >> g >> p;

    int answer = 0;
    for (int i = 1; i <= p; i++){
        cin >> gates[i];
        gateRoot[i] = i;
    }

    for (int i = 1; i <= p; i++){
        int cur = min(g, gates[i]);
        bool cancel = true;

        cur = findRoot(cur);
        if (cur == -1){
            cout << answer;
            return 0;
        }
        else{
            answer++;
            gateRoot[cur]--;
        }
    }
    cout << answer;
}