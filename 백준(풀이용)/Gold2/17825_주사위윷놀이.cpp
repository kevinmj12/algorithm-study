#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int marker[4] = {0, 0, 0, 0};
int dices[10];
int answer = 0;

int moveSpecial(int curDice, int targetMarker){
    while (curDice-- && targetMarker >= -40){
        if (targetMarker == -13 || targetMarker == -16){
            targetMarker -= 3;
        }
        else if (targetMarker == -22){
            targetMarker -= 2;
        }
        else if (targetMarker == -28 || targetMarker == -27 || targetMarker == -26){
            targetMarker++;
        }
        else if (-40 <= targetMarker && targetMarker <= -25){
            targetMarker -= 5;
        }
        else if (targetMarker == -19 || targetMarker == -24){
            targetMarker = -25;
        }
    }
    return targetMarker;
}

// 윷놀이판 외곽을 제외한 중심부에 있는 말은 음수로 처리
void tracking(int dice, int score){
    // 주사위를 전부 굴렸다면
    if (dice >= 10){
        answer = max(answer, score);
        return;
    }
    for (int i = 0; i < 4; i++){
        int curDice = dices[dice];
        int targetMarker = marker[i];
        int addScore = 0;
        // 도착점에 있는 경우
        if (targetMarker > 40){
            continue;
        }
        // 10인 경우
        else if (targetMarker == 10){
            curDice--;
            targetMarker = -13;
            targetMarker = moveSpecial(curDice, targetMarker);
            addScore = -targetMarker;
        }
        // 20인 경우
        else if (targetMarker == 20){
            curDice--;
            targetMarker = -22;
            targetMarker = moveSpecial(curDice, targetMarker);
            addScore = -targetMarker;
        }
        // 30인 경우
        else if (targetMarker == 30){
            curDice--;
            targetMarker = -28;
            targetMarker = moveSpecial(curDice, targetMarker);
            addScore = -targetMarker;
        }
        // 음수인 경우(윷놀이판 중앙에 위치한 경우)
        else if (targetMarker < 0){
            targetMarker = moveSpecial(curDice, targetMarker);
            // 만약 -40을 넘었다면
            if (targetMarker == -45){
                addScore = 0;
                targetMarker = 45;
            }
            // 도착하지 못했다면
            else{
                addScore = -targetMarker;
                if (targetMarker == -40){
                    targetMarker = 40;
                }
            }
        }
        // 그 이외의 경우
        else{
            targetMarker += (curDice * 2);
            // 만약 40을 넘어 도착했다면
            if (targetMarker > 40){
                addScore = 0;
            }
            // 도착하지 못했다면
            else{
                addScore = targetMarker;
            }
        }
        // 만약 이동하려는 칸에 다른 말이 있었다면
        bool isDuplicate = false;
        for (int j = 0; j < 4; j++){
            if (marker[j] == targetMarker && targetMarker <= 40){
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate){
            continue;
        }
        // 백트래킹
        int tmp = marker[i];
        marker[i] = targetMarker;
        tracking(dice+1, score+addScore);
        marker[i] = tmp;
    }
}

int main(){
    for (int i = 0; i < 10; i++){
        cin >> dices[i];
    }

    tracking(0, 0);
    cout << answer;
}