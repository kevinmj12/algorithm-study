#include <string>
#include <vector>

using namespace std;

vector<int> answer = {0, 0};
int dRate[4] = {10, 20, 30, 40};

pair<int, int> simulate(vector<vector<int>> users, vector<int> emoticons, vector<int> discounts){
    int plusCnt = 0;
    int totalPrice = 0;
    
    for (vector<int> user: users){
        int price = 0;
        int d = user[0];
        int plusPrice = user[1];
        for (int i = 0; i < emoticons.size(); i++){
            if (discounts[i] >= d){
                price += emoticons[i] / 100 * (100-discounts[i]);
            }
        }
        if (price >= plusPrice){
            plusCnt++;
        }
        else{
            totalPrice += price;
        }
    }
    
    return {plusCnt, totalPrice};
}

void solve(vector<vector<int>> users, vector<int> emoticons, vector<int> discounts){
    if (discounts.size() == emoticons.size()){
        pair<int, int> result = simulate(users, emoticons, discounts);
        if (result.first > answer[0] ||
           result.first == answer[0] && result.second > answer[1]){
            answer[0] = result.first;
            answer[1] = result.second;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++){
        discounts.push_back(dRate[i]);
        solve(users, emoticons, discounts);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    solve(users, emoticons, {});    
    
    return answer;
}