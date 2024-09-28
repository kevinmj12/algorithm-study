#include <iostream>
using namespace std;

int graph[100][100];

int main(){
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++){
        // 가로 체크
        int height = graph[i][0];
        int continuous = 1;
        bool rowFlag = true;
        for (int j = 1; j < n; j++){
            // 이전 높이와 동일한 경우
            if (graph[i][j] == height){
                continuous++;
            }
            // 이전 높이보다 높아진 경우
            else if (graph[i][j] == height+1){
                if (continuous >= l){
                    height = graph[i][j];
                    continuous = 1;
                }
                else{
                    rowFlag = false;
                    break;
                }
            }
            // 이전 높이보다 낮아진 경우
            else if (graph[i][j] == height-1){
                int checkJ = j+l-1;
                if (checkJ >= n){
                    rowFlag = false;
                    break;
                }
                bool lowFlag = true;
                for (j; j < checkJ; j++){
                    if (graph[i][j+1] != graph[i][j]){
                        lowFlag = false;
                        break;
                    }
                }
                if (!lowFlag){
                    rowFlag = false;
                    break;
                }
                continuous = 0;
                height = graph[i][j];
            }
            // 이외의 경우 (높이 차이가 2 이상)
            else{
                rowFlag = false;
                break;
            }
        }
        if (rowFlag){
            // cout << "row: " << i << endl;
            answer++;
        }

        // 세로 체크
        height = graph[0][i];
        continuous = 1;
        bool colFlag = true;
        for (int j = 1; j < n; j++){
            // 이전 높이와 동일한 경우
            if (graph[j][i] == height){
                continuous++;
            }
            // 이전 높이보다 높아진 경우
            else if (graph[j][i] == height+1){
                if (continuous >= l){
                    height = graph[j][i];
                    continuous = 1;
                }
                else{
                    colFlag = false;
                    break;
                }
            }
            // 이전 높이보다 낮아진 경우
            else if (graph[j][i] == height-1){
                int checkJ = j+l-1;
                if (checkJ >= n){
                    colFlag = false;
                    break;
                }
                bool lowFlag = true;

                for (j; j < checkJ; j++){
                    if (graph[j+1][i] != graph[j][i]){
                        lowFlag = false;
                        break;
                    }
                }
                if (!lowFlag){
                    colFlag = false;
                    break;
                }
                continuous = 0;
                height = graph[j][i];
            }
            else{
                colFlag = false;
                break;
            }
        }
        if (colFlag){
            // cout << "col: " << i << endl;
            answer++;
        }
    }

    cout << answer;
}