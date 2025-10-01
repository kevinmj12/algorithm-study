#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

using namespace std;


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    vector<set<int>> reported(id_list.size()+1, set<int>());
    
    int idx = 1;
    map<string, int> idMap;
    map<int, string> idxMap;
    
    for (string id: id_list){
        idMap.insert({id, idx});
        idxMap.insert({idx, id});
        idx++;
    }
    
    for (string r: report){
        stringstream ss(r);
        vector<string> words;
        string word;
        
        while (getline(ss, word, ' ')){
            words.push_back(word);
        }
        reported[idMap[words[1]]].insert(idMap[words[0]]);
    }
    
    for (int i = 1; i < idx; i++){
        if (reported[i].size() >= k){
            for (int j: reported[i]){
                answer[j-1]++;
            }
        }
    }
    
    return answer;
}