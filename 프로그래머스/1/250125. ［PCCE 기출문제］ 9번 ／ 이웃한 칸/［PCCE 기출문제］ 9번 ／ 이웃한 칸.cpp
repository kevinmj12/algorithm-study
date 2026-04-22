#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string trg = board[h][w];
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for (int d = 0; d < 4; d++){
        int nextY = h + dirs[d][0];
        int nextX = w + dirs[d][1];
        if (nextY < 0 || nextY >= board.size() ||
           nextX < 0 || nextX >= board[0].size()){
            continue;
        }
        
        if (board[nextY][nextX] == trg){
            answer++;
        }
    }
    
    return answer;
}