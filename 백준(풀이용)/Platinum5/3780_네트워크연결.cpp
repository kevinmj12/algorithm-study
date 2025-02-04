#include <iostream>
using namespace std;
#define MAX 200001

int arr[MAX];
int dis[MAX];

void resetArr(int n){
    for (int i = 1; i <= n; i++){
        arr[i] = i;
        dis[i] = 0;
    }
}

int Find(int x){
    if (arr[x] == x){
        return x;
    }
    int par = Find(arr[x]);
    dis[x] += dis[arr[x]];
    return arr[x] = par;
}

void Union(int x, int y){
    dis[x] = abs(x-y) % 1000;
    arr[x] = y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;

        resetArr(N);

        while (true){
            char c;
            cin >> c;

            if (c == 'E'){
                int a;
                cin >> a;

                Find(a);
                cout << dis[a] << "\n";
            }
            else if (c == 'I'){
                int a, b;
                cin >> a >> b;

                Union(a, b);
            }
            else{
                break;
            }
        }
    }
}