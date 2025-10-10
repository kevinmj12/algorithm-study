#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<int>> m;
vector<int> scores;

void backtracking(int idx, vector<string> vecInfo, string key, int score){
    if (idx == 4){
        m[key].push_back(score);
        return;
    }
    backtracking(idx+1, vecInfo, key+vecInfo[idx], score);
    backtracking(idx+1, vecInfo, key, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (int i = 0; i < info.size(); i++){
        string s = info[i];
        
        vector<string> vecInfo;
        int idx = 0;
        int left = 0;
        while (idx < s.length()){
            if (s[idx] == ' '){
                string word = s.substr(left, idx-left);
                left = idx+1;
                vecInfo.push_back(word);
            }
            idx++;
        }
        backtracking(0, vecInfo, "", stoi(s.substr(left)));
    }
    
    for (auto& a: m){
        sort(a.second.begin(), a.second.end());
    }
        
    for (string q: query){
        vector<bool> condition(info.size(), true);
        int idx = 0;
        int left = 0;
        string key = "";
        while (idx < q.length()){
            if (q[idx] == ' '){
                string word = q.substr(left, idx-left);
                left = idx+1;
                if (word == "and"){
                    continue;
                }
                else if (word == "java" || word == "python" || word == "cpp"){
                    key += word;
                }
                else if (word == "senior" || word == "junior"){
                    key += word;
                }
                else if (word == "backend" || word == "frontend"){
                    key += word;
                }
                else if (word == "chicken" || word == "pizza"){
                    key += word;
                }
            }
            idx++;
        }
        
        vector<int> candidates = m[key];
        int score = stoi(q.substr(left));
        
        vector<int>::iterator it = lower_bound(candidates.begin(), candidates.end(), score);
        answer.push_back(candidates.end() - it);
    }
    
    return answer;
}