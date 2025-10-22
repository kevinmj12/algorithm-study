#include <string>
#include <vector>

using namespace std;

int board[100][100];

vector<vector<int>> rotate(vector<vector<int>> key, int kLen){
    vector<vector<int>> rotateKey(kLen, vector<int>(kLen, 0));
    for (int i = 0; i < kLen; i++){
        for (int j = 0; j < kLen; j++){
            rotateKey[j][kLen-1-i] = key[i][j];
        }
    }
    
    return rotateKey;
}

bool solve(vector<vector<int>> key, int kLen, int lLen, int hole){
    for (int i = 0; i <= kLen+lLen-2; i++){
        for (int j = 0; j <= kLen+lLen-2; j++){
            bool flag = true;
            int filled = 0;
            
            for (int y = 0; y < kLen; y++){
                if (!flag){
                    break;
                }
                for (int x = 0; x < kLen; x++){
                    if (i+y < kLen-1 || kLen+lLen-2 < i+y ||
                       j+x < kLen-1 || kLen+lLen-2 < j+x){
                        continue;
                    }
                    if (board[i+y][j+x] == 1){
                        if (key[y][x] == 1){
                            flag = false;
                            break;
                        }
                    }
                    else{
                        if (key[y][x] == 1){
                            filled++;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                }
            }
            
            if (flag && (filled == hole)){
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int kLen = key.size();
    int lLen = lock.size();
    
    int hole = 0;
    for (int i = 0; i < lLen; i++){
        for (int j = 0; j < lLen; j++){
            board[i+kLen-1][j+kLen-1] = lock[i][j];
            if (lock[i][j] == 0){
                hole++;
            }
        }
    }
    
    // 네 방향(회전)
    for (int d = 0; d < 4; d++){
        key = rotate(key, kLen);
        
        answer = solve(key, kLen, lLen, hole);
        if (answer){
            return answer;
        }
    }
    
    return answer;
}