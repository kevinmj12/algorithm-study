#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define MAX_S 50001
#define MAX_I 10000001

using namespace std;

set<int> summitsSet;
int answerS = 0;
int answerI = MAX_I;

vector<pair<int, int>> graph[MAX_S];
bool visited[MAX_S];
int dijkIntensity[MAX_S];
vector<int> connectedSpots;

void reset(int n){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        dijkIntensity[i] = MAX_I;
    }
    connectedSpots.clear();
}

bool isSummit(int spot){
    if (summitsSet.find(spot) != summitsSet.end()){
        return true;
    }
    return false;
}

pair<int, int> findMinIntensity(int n, int spot){
    int minIntensity = MAX_I;
    int minSpot;
    
    for (int i = 0; i < connectedSpots.size(); i++){
        int nextS = connectedSpots[i];
        int nextI = dijkIntensity[nextS];
        
        if (!visited[nextS] && nextI < minIntensity){
            minIntensity = nextI;
            minSpot = nextS;
        }
    }
    if (minIntensity == MAX_I){
        return {-1, -1};
    }
    return {minSpot, minIntensity};
}

void updateIntensity(int spot, int intensity){
    for (int i = 0; i < graph[spot].size(); i++){
        int nextS = graph[spot][i].first;
        int nextI = graph[spot][i].second;
        
        if (dijkIntensity[nextS] == MAX_I){
            connectedSpots.push_back(nextS);
        }
        dijkIntensity[nextS] = min(dijkIntensity[nextS], max(intensity, nextI));
    }
}

void solve(int n, int gate){
    while (true){
        pair<int, int> next = findMinIntensity(n, gate);
        int nextSpot = next.first;
        int nextIntensity = next.second;

        if (nextSpot == -1 || nextIntensity > answerI){
            return;
        }
        
        visited[nextSpot] = true;
        
        if (isSummit(nextSpot)){
            if (nextIntensity < answerI || (nextIntensity == answerI && nextSpot < answerS)){
                answerI = nextIntensity;
                answerS = nextSpot;
            }
            continue;
        }
        
        updateIntensity(nextSpot, nextIntensity);
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for (int path = 0; path < paths.size(); path++){
        int i = paths[path][0];
        int j = paths[path][1];
        int w = paths[path][2];
        graph[i].push_back({j, w});
        graph[j].push_back({i, w});
    }
    
    for (int i = 0; i < summits.size(); i++){
        summitsSet.insert(summits[i]);
    }
    
    for (int i = 0; i < gates.size(); i++){
        reset(n);        
        int gate = gates[i];
        visited[gate] = true;
        
        updateIntensity(gate, 0);
        solve(n, gate);
    }
    
    answer.push_back(answerS);
    answer.push_back(answerI);
    
    return answer;
}