#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 방송 시간을 계산해주는 함수
int calTime(string start, string end){
    int hour = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    int minute = stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));
    return hour * 60 + minute;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, vector<vector<int>>> youtubers;
    
    for (int i = 0; i < n; i++){
        string name, startTime, endTime;
        int date;
        cin >> name >> date >> startTime >> endTime;

        if (youtubers.find(name) == youtubers.end()){
            vector<vector<int>> vec(m/7, vector<int>(2, 0));
            youtubers.insert({name, vec});
        }
        youtubers[name][(date-1)/7][0]++;
        youtubers[name][(date-1)/7][1] += calTime(startTime, endTime);
    }

    vector<string> realVirtualYoutubers;
    for (auto it = youtubers.begin(); it != youtubers.end(); it++){
        // 진짜 버츄얼 유튜버인지 체크
        bool isRealVirtualYoutuber = true;
        for (int i = 0; i < m/7; i++){
            if (it->second[i][0] < 5 || it->second[i][1] < 3600){
                isRealVirtualYoutuber = false;
                break;
            }
        }
        if (isRealVirtualYoutuber){
            realVirtualYoutubers.push_back(it->first);
        }
    }
    
    if (realVirtualYoutubers.size()){
        for (int i = 0; i < realVirtualYoutubers.size(); i++){
            cout << realVirtualYoutubers[i] << "\n";
        }
    }
    else{
        cout << -1;
    }
}