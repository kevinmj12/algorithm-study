#include <iostream>
#include <algorithm>
using namespace std;

bool graph[51][51];

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string info;
        cin >> info;

        for (int j = i+1; j < N; j++){
            if (info[j] == 'Y'){
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++){
        int twoFriends = 0;
        for (int j = 0; j < N; j++){
            if (i == j){
                continue;
            }
            else if (graph[i][j]){
                twoFriends++;
            }
            else{
                for (int k = 0; k < N; k++){
                    if (k == i || k == j){
                        continue;
                    }
                    if (graph[i][k] && graph[j][k]){
                        twoFriends++;
                        break;
                    }
                }
            }
        }

        answer = max(answer, twoFriends);
    }

    cout << answer;
    return 0;
}