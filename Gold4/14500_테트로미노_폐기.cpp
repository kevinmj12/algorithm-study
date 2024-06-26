#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[501][501];
int rowSum[501][501];
int colSum[501][501];

int answer = 0;

// 일자 테트로미노 판단
void caseOne(){
    // 가로
    for (int i = 1; i <= n; i++){
        for (int j = 4; j <= m; j++){
            answer = max(answer, rowSum[i][j]-rowSum[i][j-4]);
        }
    }
    // 세로
    for (int j = 1; j <= m; j++){
        for (int i = 4; i <= n; i++){
            answer = max(answer, colSum[i][j]-colSum[i-4][j]);
        }
    }
}

// 정사각형 테트로미노 판단
void caseTwo(){
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= m; j++){
            answer = max(answer, graph[i][j]+graph[i-1][j]+graph[i][j-1]+graph[i-1][j-1]);
        }
    }
}

// 'ㄴ'자 테트로미노 판단
void caseThree(){
    // 가로로 길 때
    for (int i = 1; i <= n; i++){
        for (int j = 3; j <= m; j++){
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i-1][j-2]);
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i-1][j]);
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i+1][j-2]);
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i+1][j]);
        }
    }
    // 세로로 길 때
    for (int j = 1; j <= m; j++){
        for (int i = 3; i <= n; i++){
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i-2][j-1]);
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i][j-1]);
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i-2][j+1]);
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i][j+1]);
        }
    }
}

// 지그재그 테트로미노 판단
void caseFour(){
    // 가로
    for (int i = 2; i <= n; i++){
        for (int j = 3; j <= m; j++){
            answer = max(answer, graph[i][j]+graph[i][j-1]+graph[i-1][j-1]+graph[i-1][j-2]);
            answer = max(answer, graph[i-1][j]+graph[i-1][j-1]+graph[i][j-1]+graph[i][j-2]);
        }
    }
    // 세로
    for (int j = 2; j <= m; j++){
        for (int i = 3; i <= n; i++){
            answer = max(answer, graph[i][j]+graph[i-1][j]+graph[i-1][j-1]+graph[i-2][j-1]);
            answer = max(answer, graph[i][j-1]+graph[i-1][j-1]+graph[i-1][j]+graph[i-2][j]);
        }
    }
}

// 'ㅜ'자 테트로미노 판단
void caseFive(){
    // 가로
    for (int i = 1; i <= n; i++){
        for (int j = 3; j <= m; j++){
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i-1][j-1]);
            answer = max(answer, rowSum[i][j]-rowSum[i][j-3]+graph[i+1][j-1]);
        }
    }
    // 세로
    for (int j = 1; j <= m; j++){
        for (int i = 3; i <= n; i++){
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i-1][j-1]);
            answer = max(answer, colSum[i][j]-colSum[i-3][j]+graph[i-1][j+1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> graph[i][j];
            rowSum[i][j] = rowSum[i][j-1]+graph[i][j];
            colSum[i][j] = colSum[i-1][j]+graph[i][j];
        }
    }

    caseOne();
    caseTwo();
    caseThree();
    caseFour();
    caseFive();

    cout << answer;
}