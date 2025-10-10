#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string excel[51][51];
pair<int, int> root[51][51];

void init(){
    for (int i = 1; i <= 50; i++){
        for (int j = 1; j <= 50; j++){
            root[i][j] = {i, j};
        }
    }
}

pair<int, int> find(int r, int c){
    if (root[r][c] == make_pair(r, c)){
        return {r, c};
    }
    return find(root[r][c].first, root[r][c].second);
}

void merge(int r1, int c1, int r2, int c2){  
    pair<int, int> x = find(r1, c1);
    pair<int, int> y = find(r2, c2);
    if (x == y){
        return;
    }
    
    if (excel[x.first][x.second].length() >= 1){
        root[y.first][y.second] = x;
        excel[y.first][y.second] = "";
    }
    else {
        root[x.first][x.second] = y;
        excel[x.first][x.second] = "";
    }
}

void updateCel(vector<string> words){
    // r, c에 value
    if (words.size() == 4){
        int r1 = stoi(words[1]);
        int c1 = stoi(words[2]);
        pair<int, int> r = find(r1, c1);
        excel[r.first][r.second] = words[3];
    }
    // value1을 value2로
    else{
        for (int i = 1; i <= 50; i++){
            for (int j = 1; j <= 50; j++){
                if (excel[i][j] == words[1]){
                    excel[i][j] = words[2];
                }
            }
        }
    }
}

void mergeCel(vector<string> words){
    // 같은 셀일 경우 무시
    int r1 = stoi(words[1]), c1 = stoi(words[2]), r2 = stoi(words[3]), c2 = stoi(words[4]);
    if (r1 == r2 && c1 == c2){
        return;
    }
    // 병합   
    merge(r1, c1, r2, c2);
}

void unmergeCel(vector<string> words){
    int r1 = stoi(words[1]), c1 = stoi(words[2]);
    pair<int, int> r = find(r1, c1);
    string val = excel[r.first][r.second];
    
    vector<pair<int, int>> vec;
    for (int i = 1; i <= 50; i++){
        for (int j = 1; j <= 50; j++){
            if (find(i, j) == r){
                vec.push_back({i, j});
            }
        }
    }
    
    for (auto i: vec){
        root[i.first][i.second] = {i.first, i.second};
        excel[i.first][i.second] = "";
    }
    
    excel[r1][c1] = val;
}

string printCel(vector<string> words){
    int r1 = stoi(words[1]), c1 = stoi(words[2]);
    pair<int, int> r = find(r1, c1);
    
    if (excel[r.first][r.second].length() >= 1){
        return excel[r.first][r.second];
    }
    else{
        return "EMPTY";
    }
}

vector<string> solution(vector<string> commands) {
    init();
    vector<string> answer;
    
    for (string c: commands){
        stringstream ss(c);
        string word;
        vector<string> words;
        
        while(ss >> word){
            words.push_back(word);
        }
        
        if (words[0] == "UPDATE"){
            updateCel(words);
        }
        else if (words[0] == "MERGE"){
            mergeCel(words);
        }
        else if (words[0] == "UNMERGE"){
            unmergeCel(words);
        }
        else if (words[0] == "PRINT"){
            answer.push_back(printCel(words));
        }
        // for (int i = 1; i <= 4; i++){
        //     for (int j = 1; j <= 4; j++){
        //         cout << excel[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    
    return answer;
}