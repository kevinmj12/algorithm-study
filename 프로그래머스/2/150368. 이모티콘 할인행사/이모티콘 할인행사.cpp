#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int discount[4] = {10, 20, 30, 40};
int maxPeople = 0;
int maxMoney = 0;
using namespace std;

void backtracking(int idx, int m, vector<int> discounts, vector<vector<int>> users, vector<int> emoticons){
    if (idx == m){
        vector<int> dcEmoticons;
        int people = 0, money = 0;
        
        for (int i = 0; i < m; i++){
            dcEmoticons.push_back(emoticons[i] / 100 * (100 - discounts[i]));
        }
        for (int i = 0; i < users.size(); i++){
            int tmpMoney = 0;
            for (int j = 0; j < discounts.size(); j++){
                if (users[i][0] <= discounts[j]){
                    tmpMoney += dcEmoticons[j];
                }
            }
            // 플러스 서비스 가입 여부 확인
            if (tmpMoney >= users[i][1]){
                people++;
            }
            else{
                money += tmpMoney;
            }
        }
        if (people > maxPeople){
            maxPeople = people;
            maxMoney = money;
        }
        else if (people == maxPeople){
            maxMoney = max(maxMoney, money);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        discounts.push_back(discount[i]);
        backtracking(idx+1, m, discounts, users, emoticons);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    backtracking(0, emoticons.size(), {}, users, emoticons);
    
    answer.push_back(maxPeople);
    answer.push_back(maxMoney);
    return answer;
}