#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compareC(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
bool compareD(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
bool compareM(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
bool compareR(vector<int> a, vector<int> b){
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < data.size(); i++){
        int e;
        if (ext == "code"){
            e = 0;
        }
        else if (ext == "date"){
            e = 1;
        }
        else if (ext == "maximum"){
            e = 2;
        }
        else{
            e = 3;
        }
        
        
        if (data[i][e] < val_ext){
            answer.push_back(data[i]);
        }
    }
    
    if (sort_by == "code"){
        sort(answer.begin(), answer.end(), compareC);
    }
    else if (sort_by == "date"){
        sort(answer.begin(), answer.end(), compareD);
    }
    else if (sort_by == "maximum"){
        sort(answer.begin(), answer.end(), compareM);
    }
    else{
        sort(answer.begin(), answer.end(), compareR);
    }
    
    
    return answer;
}