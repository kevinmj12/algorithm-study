#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int giftCnt[50][50][2];
int giftScore[50];
int giftCntNextMonth[50];

int findIndex(string name, vector<string> friends){
    for (int i = 0; i < friends.size(); i++){
        if (name == friends[i]){
            return i;
        }
    }
}

int getGiftScore(int aIndex, int size){
    int aScore = 0;
    for (int i = 0; i < size; i++){
        aScore += giftCnt[aIndex][i][0] - giftCnt[aIndex][i][1];
    }
    return aScore;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 먼저 선물 기록을 저장
    for (int i = 0; i < gifts.size(); i++){
        string aName = "", bName = "";
        bool findSpace = false;
        for (int j = 0; j < gifts[i].length(); j++){
            if (gifts[i][j] == ' '){
                findSpace = true;
            }
            else if (!findSpace){
                aName += gifts[i][j];
            }
            else{
                bName += gifts[i][j];
            }
        }
        
        int aIndex = findIndex(aName, friends);
        int bIndex = findIndex(bName, friends);
        
        giftCnt[aIndex][bIndex][0]++;
        giftCnt[bIndex][aIndex][1]++;
    }
    
    // 먼저 선물 점수를 전부 계산
    for (int i = 0; i < friends.size(); i++){
        giftScore[i] = getGiftScore(i, friends.size());
    }
    
    // 다음 달 친구들 선물 반영
    for (int i = 0; i < friends.size()-1; i++){
        for (int j = i+1; j < friends.size(); j++){
            int aIndex = findIndex(friends[i], friends);
            int bIndex = findIndex(friends[j], friends);
            int aToB = giftCnt[aIndex][bIndex][0];
            int bToA = giftCnt[bIndex][aIndex][0];
            
            // a가 선물을 더 많이 준 경우
            if (aToB > bToA){
                giftCntNextMonth[aIndex]++;
            }
            // b가 선물을 더 많이 준 경우
            else if (bToA > aToB){
                giftCntNextMonth[bIndex]++;
            }
            // 선물을 준 횟수가 같은 경우
            else{
                if (giftScore[i] > giftScore[j]){
                    giftCntNextMonth[aIndex]++;
                }
                else if (giftScore[i] < giftScore[j]){
                    giftCntNextMonth[bIndex]++;
                }
            }
        }
    }
    // 정답 설정
    for (int i = 0; i < friends.size(); i++){
        answer = max(answer, giftCntNextMonth[i]);
    }
    
    return answer;
}