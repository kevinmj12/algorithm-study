#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> courses[11];

void backtracking(string original, string s, int index, int length){
    if (s.length() == length){
        courses[length].push_back(s);
        return;
    }
    for (int i = index; i < original.length(); i++){
        backtracking(original, s+original[i], i+1, length);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < orders.size(); i++){
        vector<char> tmp;
        for (int j = 0; j < orders[i].length(); j++){
            tmp.push_back(orders[i][j]);
        }
        sort(tmp.begin(), tmp.end());
        string tmpOrder = "";
        for (int j = 0; j < tmp.size(); j++){
            tmpOrder += tmp[j];
        }
        
        for (int j = 0; j < course.size(); j++){
            backtracking(tmpOrder, "", 0, course[j]);
        }
    }
    
    for (int j = 0; j < course.size(); j++){
        vector<string> vec = courses[course[j]];
        sort(vec.begin(), vec.end());
         
        int maxCnt = 2;
        vector<string> tmpAnswer;
        for (int i = 0; i < vec.size(); i++){
            int cnt = 1;
            while (i + 1 < vec.size() && vec[i] == vec[i+1]){
                i++;
                cnt++;
            }
            if (cnt > maxCnt){
                maxCnt = cnt;
                tmpAnswer.clear();
                tmpAnswer.push_back(vec[i]);
            }
            else if (cnt == maxCnt){
                tmpAnswer.push_back(vec[i]);
            }
        }
        
        for (int i = 0; i < tmpAnswer.size(); i++){
            answer.push_back(tmpAnswer[i]);
        }
        
        sort(answer.begin(), answer.end());
    }
    
    
    
    return answer;
}