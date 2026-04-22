#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> pToR;
    map<int, string> rToP;
    
    for (int i = 0; i < players.size(); i++){
        pToR[players[i]] = i+1;
        rToP[i+1] = players[i];
    }
    
    for (int i = 0; i < callings.size(); i++){
        string p1 = callings[i];
        int r1 = pToR[p1];
        int r2 = r1-1;
        string p2 = rToP[r1-1];
        
        pToR[p1] = r2;
        pToR[p2] = r1;
        rToP[r2] = p1;
        rToP[r1] = p2;
    }
    
    for (int i = 1; i <= players.size(); i++){
        answer.push_back(rToP[i]);
    }
    
    return answer;
}