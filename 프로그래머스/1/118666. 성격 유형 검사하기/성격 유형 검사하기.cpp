#include <string>
#include <vector>

using namespace std;

int score[4]; // RT / CF / JM / AN
char name[4][2] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};

void addScore(string survey, int choice){
    int m = choice % 4;
    if (m == 0){
        return;
    }
    
    int p = survey[choice / 4];
    int scoreIndex;
    int scorePlus = 1;
    if (p == 'R' || p == 'T'){
        scoreIndex = 0;
    }
    else if (p == 'C' || p == 'F'){
        scoreIndex = 1;
    }
    else if (p == 'J' || p == 'M'){
        scoreIndex = 2;
    }
    else{
        scoreIndex = 3;
    }
    
    
    if (p == 'T' || p == 'F' || p == 'M' || p == 'N'){
        scorePlus = -1;
    }
    
    if (choice / 4 == 0){
        score[scoreIndex] += scorePlus * (4 - m);   
    }
    else{
        score[scoreIndex] += scorePlus * m;   
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < survey.size(); i++){
        addScore(survey[i], choices[i]);
    }
    
    for (int i = 0; i < 4; i++){
        if (score[i] >= 0){
            answer += name[i][0];
        }
        else{
            answer += name[i][1];
        }
    }
    
    return answer;
}