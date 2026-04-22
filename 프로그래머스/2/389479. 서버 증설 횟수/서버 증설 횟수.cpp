#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    vector<int> maxPlayers(players.size(), m);
    
    for (int i = 0; i < players.size(); i++){
        if (players[i] >= maxPlayers[i]){
            int addServers = (players[i] - maxPlayers[i]) / m + 1;
            answer += addServers;
            
            for (int j = 0; j < k; j++){
                if (i + j >= players.size()){
                    break;
                }
                maxPlayers[i+j] += addServers * m;
            }
        }
    }
    
    return answer;
}