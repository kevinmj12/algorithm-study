#include <iostream>
#include <vector>
using namespace std;

struct Shark{
    int r, c, s, d, z;
    bool alive = true;

    Shark(int R, int C, int S, int D, int Z): r(R), c(C), s(S), d(D), z(Z) {} 
};

int R, C, M;
int graph[101][101];
vector<Shark> sharks;
int direction[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int changeDir[4] = {2,1,4,3};
int kingPos = 0;
int answer = 0;

void moveKing(){
    kingPos++;
}

void catchShark(){
    for (int i = 1; i <= R; i++){
        if (graph[i][kingPos] != -1){
            answer += sharks[graph[i][kingPos]].z;
            sharks[graph[i][kingPos]].alive = false;
            break;
        }
    }
}

void moveShark(){
    for (int i = 0; i < sharks.size(); i++){
        if (sharks[i].alive){
            int y = sharks[i].r;
            int x = sharks[i].c;
            int s = sharks[i].s;
            int d = sharks[i].d;
            int z = sharks[i].z;
            
            int tmpS = s;

            while (tmpS > 0){
                if (d == 1){
                    if (tmpS >= y-1){
                        tmpS -= (y-1);
                        y = 1;
                        d = 2;
                    }
                    else{
                        y -= tmpS;
                        tmpS = 0;
                    }
                }
                else if (d == 2){
                    if (tmpS >= R-y){
                        tmpS -= (R-y);
                        y = R;
                        d = 1;
                    }
                    else{
                        y += tmpS;
                        tmpS = 0;
                    }
                }
                else if (d == 3){
                    if (tmpS >= C-x){
                        tmpS -= (C-x);
                        x = C;
                        d = 4;
                    }
                    else{
                        x += tmpS;
                        tmpS = 0;
                    }
                }
                else{
                    if (tmpS >= x-1){
                        tmpS -= (x-1);
                        x = 1;
                        d = 3;
                    }
                    else{
                        x -= tmpS;
                        tmpS = 0;
                    }
                }
            }

            sharks[i].r = y;
            sharks[i].c = x;
            sharks[i].d = d;
        }
    }
    

    // 그래프 초기화
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            graph[i][j] = -1;
        }
    }

    // 한 칸에 상어가 여러 마리 있으면 잡아먹음
    for (int i = 0; i < sharks.size(); i++){
        if (sharks[i].alive){
            if (graph[sharks[i].r][sharks[i].c] == -1){
                graph[sharks[i].r][sharks[i].c] = i;
            }
            else{
                if (sharks[graph[sharks[i].r][sharks[i].c]].z < sharks[i].z){
                    sharks[graph[sharks[i].r][sharks[i].c]].alive = false;
                    graph[sharks[i].r][sharks[i].c] = i;
                }
                else{
                    sharks[i].alive = false;
                }
            }
        }
    }
}

int main(){
    cin >> R >> C >> M;

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        
        if (d <= 2){
            s = s%((R-1)*2);
        }
        else{
            s = s%((C-1)*2);
        }

        sharks.push_back(Shark(r, c, s, d, z));
        graph[r][c] = i;
    }

    while (kingPos < C){
        moveKing();
        catchShark();
        moveShark();
    }
    cout << answer;
}