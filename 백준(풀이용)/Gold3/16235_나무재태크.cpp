#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
int a[101][101];
int graph[101][101];
deque<int> trees[101][101];
queue<pair<int, pair<int, int>>> deadTrees;  
queue<pair<int, int>> breedingTrees;

int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};



// 지력 흡수
void absorbLand(int m){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            deque<int> tmp;
            int size = trees[i][j].size();
            for (int k = 0; k < size; k++){
                int tree = trees[i][j].front();
                trees[i][j].pop_front();
                // 지력이 충분한 경우
                if (graph[i][j] >= tree){
                    graph[i][j] -= tree;
                    tree++;
                    tmp.push_back(tree);
                    // 나무의 나이가 5의 배수인 경우
                    if (tree % 5 == 0){
                        breedingTrees.push({i, j});
                    }
                }
                // 지력이 충분하지 못하여 나무가 죽은 경우
                else{
                    deadTrees.push({tree,{i, j}});
                }
            }
            trees[i][j] = tmp;
        }
    }
}
// 나무의 죽음
void dead(int m){
    while (!deadTrees.empty()){
        int tree = deadTrees.front().first;
        int y = deadTrees.front().second.first;
        int x = deadTrees.front().second.second;
        deadTrees.pop();
        graph[y][x] += tree/2;
    }
}
// 나무의 번식
void breeding(int m){
    while(!breedingTrees.empty()){
        int y = breedingTrees.front().first;
        int x = breedingTrees.front().second;
        breedingTrees.pop();
        for (int i = 0; i < 8; i++){
            int nextY = y + dir[i][0];
            int nextX = x + dir[i][1];
            if (1 <= nextY && nextY <= m && 1 <= nextX && nextX <= m){
                trees[nextY][nextX].push_front(1);
            }
        }
    }
}
// 지력 회복
void recovering(int m){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            graph[i][j] += a[i][j];
        }
    }
}
// 정답 출력
void printAnswer(int m){
    int answer = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            answer += trees[i][j].size();
        }
    }
    cout << answer;
}

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    
    // 지력 입력받음
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            graph[i][j] = 5;
            cin >> a[i][j];
        }
    }
    // 나무 입력받음
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    while (k--){
        absorbLand(n);
        dead(n);
        breeding(n);
        recovering(n);
        // printAnswer(n);
        // cout << endl;
    }
    printAnswer(n);
    
}