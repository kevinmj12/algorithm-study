#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> answer;
int maxWins = 0;

void calculateCase(vector<vector<int>> dice, vector<int> selectedDice, int diceIndex, int answer, vector<int>& cases);
int binarySearch(int target, vector<int> vec);

void backTracking(vector<vector<int>> dice, int diceIndex, vector<int> aDice){
    if (aDice.size() == dice.size()/2){
        // b가 고른 주사위들을 고름
        vector<int> bDice;
        int aIndex = 0;
        for (int i = 0; i < dice.size(); i++){
            if (aIndex >= dice.size()/2){
                bDice.push_back(i);
            }
            else if (aDice[aIndex] == i){
                aIndex++;
            }
            else{
                bDice.push_back(i);
            }
        }

        // a와 b가 고른 주사위로 가능한 경우의 수를 구함
        vector<int> aCase, bCase;
        calculateCase(dice, aDice, 0, 0, aCase);
        calculateCase(dice, bDice, 0, 0, bCase);
        sort(aCase.begin(), aCase.end());
        sort(bCase.begin(), bCase.end());
        
        int aWins = 0;  
        for (int i = 0; i < aCase.size(); i++){
            aWins += binarySearch(aCase[i], bCase);
        }

        if (aWins > maxWins){
            maxWins = aWins;
            answer = aDice;
        }
        return;
    }
    for (int i = diceIndex; i < dice.size(); i++){
        aDice.push_back(i);
        
        backTracking(dice, i+1, aDice);
        
        aDice.pop_back();
    }
}

void calculateCase(vector<vector<int>> dice, vector<int> selectedDice, int diceIndex, int answer, vector<int>& cases){
    if (diceIndex == selectedDice.size()){
        cases.push_back(answer);
        return;
    }
    for (int i = 0; i < 6; i++){
        calculateCase(dice, selectedDice, diceIndex+1, answer+dice[selectedDice[diceIndex]][i], cases);
    }
}

int binarySearch(int target, vector<int> vec){
    int left = 0, right = vec.size()-1;
    
    return lower_bound(vec.begin(), vec.end(), target) - vec.begin();
//     while (left < right){
//         int mid = (left + right) / 2;
    
//         if (vec[mid] < target){ 
//             left = mid+1;
//         }
//         else{
//             right = mid;
//         }
//     }
//     return right;
}


vector<int> solution(vector<vector<int>> dice) {
    backTracking(dice, 0, {});
    
    for (int i = 0; i < answer.size(); i++){
        answer[i]++;
    }
    return answer;
}