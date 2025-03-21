#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    startday--;
    
    for (int i = 0; i < schedules.size(); i++){
        int day = startday;
        bool flag = true;
        
        int deadline = schedules[i];
        // 출근 희망 시각이 50분보다 작은 경우
        if (schedules[i] % 100 < 50){
            deadline += 10;
        }
        // 50~59 사이인 경우
        else{
            int sHour = schedules[i] / 100;
            int sTime = schedules[i] % 100;
            sHour++;
            sTime -= 50;
            deadline = sHour * 100 + sTime;
        }
        
        for (int j = 0; j < timelogs[i].size(); j++){
            // 토요일, 일요일 처리
            if (day == 5 || day == 6){
                day = (day + 1) % 7;
                continue;
            }
            day = (day + 1) % 7;

            if (deadline < timelogs[i][j]){
                flag = false;
                break;
            }
        }
        if (flag){
            answer++;
        }
    }
    
    return answer;
}