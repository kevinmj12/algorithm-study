#include <iostream>
#include <vector>
using namespace std;

int n, m;
int maze[101][101];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int walls[101][101];
bool visited[101][101];

void reset(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            walls[i][j] = 10001;
        }
    }
}

void update(int y, int x){
    for (int i = 0; i < 4; i++){
        int nextY = y + dir[i][0];
        int nextX = x + dir[i][1];

        if (!visited[nextY][nextX] && 1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m){
            walls[nextY][nextX] = min(walls[nextY][nextX], walls[y][x]+maze[nextY][nextX]);
        }
    }
}

pair<int, int> findMin(){
    int minY;
    int minX;
    int minWall = 10001;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visited[i][j] && (walls[i][j] < minWall)){
                minY = i;
                minX = j;
                minWall = walls[i][j];
            }
        }
    }

    return {minY, minX};
}


int main(){
    cin >> m >> n;

    reset();

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            maze[i][j] = c-'0';
        }
    }

    int posY = 1, posX = 1;
    walls[posY][posX] = 0;
    visited[posY][posX] = true;

    while (posY != n || posX != m){
        update(posY, posX);

        pair<int, int> next = findMin();
        posY = next.first;
        posX = next.second;
        visited[posY][posX] = true;
    }

    cout << walls[n][m];
    
}