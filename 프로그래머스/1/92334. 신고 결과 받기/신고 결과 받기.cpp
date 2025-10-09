#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    vector<vector<int>> reportCnt(id_list.size(), vector<int>());
    vector<vector<bool>> reported(id_list.size(), vector<bool>(id_list.size(), false));
    
    map<string, int> idMap;
    
    for (int i = 0; i < id_list.size(); i++){
        idMap.insert({id_list[i], i});
    }
    
    for (string r : report){
        int i = 0;
        while (r[i] != ' '){
            i++;
        }
        
        int first = idMap[r.substr(0, i)];
        int second = idMap[r.substr(i+1)];
        
        if (!reported[first][second]){
            reportCnt[second].push_back(first);
            reported[first][second] = true;
        }
    }
    
    for (int i = 0; i < id_list.size(); i++){
        if (reportCnt[i].size() >= k){
            for (int j = 0; j < reportCnt[i].size(); j++){
                answer[reportCnt[i][j]]++;
            }
        }
    }
    
    return answer;
}