#include <iostream>
using namespace std;

int n, m, x, y, k;
int graph[20][20];
int dice[7];

int move(int dir){
    // 위-1 동-3 서-4 뒤-2 앞-5 아래-6
    // 동 서 북 남
    int tmp = dice[1];
    if (dir == 1){
        if (y == m-1){
            return -1;
        }
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice [4];
        dice[4] = tmp;
        y++;
    }
    else if (dir == 2){
        if (y == 0){
            return -1;
        }
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = tmp;
        y--;
    }
    else if (dir == 3){
        if (x == 0){
            return -1;
        }
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = tmp;
        x--;
    }
    else{
        if (x == n-1){
            return -1;
        }
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = tmp;
        x++;
    }

    if (graph[x][y] == 0){
        graph[x][y] = dice[6];
    }
    else{
        dice[6] = graph[x][y];
        graph[x][y] = 0;
    }
    return dice[1];
}


int main(){
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < k; i++){
        int order;
        cin >> order;

        int next = move(order);
        if (next != -1){
            cout << next << "\n";
        }
    }
}