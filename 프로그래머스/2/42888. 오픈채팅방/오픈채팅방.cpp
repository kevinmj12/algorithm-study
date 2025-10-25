#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> nameMap;
    vector<string> uidVec;
    vector<string> cmdVec;
    
    for (string str: record){
        string command = "";
        string uid = "";
        string name = "";
        
        int i = 0;
        while (str[i] != ' '){
            command += str[i];
            i++;
        }
        i++;
        
        if (command == "Leave"){
            uid = str.substr(i);
        }
        else{
            while (str[i] != ' '){
                uid += str[i];
                i++;
            }
            name = str.substr(i+1);
            nameMap[uid] = name;
        }
        
        uidVec.push_back(uid);
        cmdVec.push_back(command);
    }
    
    for (int i = 0; i < uidVec.size(); i++){
        string finalCommand = cmdVec[i];
        if (finalCommand == "Change"){
            continue;
        }
        else if (finalCommand == "Enter"){
            finalCommand = "님이 들어왔습니다.";
        }
        else if (finalCommand == "Leave"){
            finalCommand = "님이 나갔습니다.";
        }
        string finalName = nameMap[uidVec[i]];
            
        answer.push_back(finalName+finalCommand);
    }
    
    return answer;
}