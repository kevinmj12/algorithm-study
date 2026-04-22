#include <iostream>
#include <vector>
using namespace std;

int parent[201];


int find(int a){
    if (a == parent[a]){
        return a;
    }

    return parent[a] = find(parent[a]);
}


void merge(int a, int b){
    a = find(a);
    b = find(b);

    if (a != b){
        if (a < b){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> plan(M);

    for (int i = 1; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int a;
            cin >> a;
            
            if (a){
                merge(i, j);
            }
        }
    }

    for (int i = 0; i < M; i++){
        cin >> plan[i];
    }

 
    bool answer = true;
    if (M > 0){
        int base = find(plan[0]);
        for (int i = 1; i < M; i++){
            if (base != find(plan[i])){
                answer = false;
                break;
            }
        }
    }
    

    if (answer){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}