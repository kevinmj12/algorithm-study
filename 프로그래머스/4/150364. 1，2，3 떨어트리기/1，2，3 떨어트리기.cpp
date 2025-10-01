#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes[102];
int nextNode[102];
int value[102];

vector<int> trace[102];
vector<int> sequence;
int seqIndex[102];


vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    int totalValue = 0;
    for (int t : target){
        totalValue += t;
    }
    
    for (int i = 0; i < edges.size(); i++){
        nodes[edges[i][0]].push_back(edges[i][1]);
    }
    for (int i = 1; i <= edges.size()+1; i++){
        sort(nodes[i].begin(), nodes[i].end());
    }
    
    while (totalValue){
        int cur = 1;
        while (!nodes[cur].empty()){
            int next = nextNode[cur];
            nextNode[cur] = (next+1) % nodes[cur].size();
            cur = nodes[cur][next];
        }
        
        int v = min(3, target[cur-1] - value[cur]);
        totalValue -= v;
        value[cur] += v;
        trace[cur].push_back(v);
        sequence.push_back(cur);
    }
    
    bool flag = true;
    // 사전 순으로 배치
    for (int i = 1; i <= edges.size()+1; i++){
        int s = trace[i].size();
        if (s <= 1){
            continue;
        }
        
        int t = target[i-1];
        if (s > t){
            flag = false;
            break;
        }
        
        for (int j = trace[i].size()-1; j >= 0; j--){
            if (t >= s+2){
                trace[i][j] = 3;
                t -= 3;
            }
            else if (t == s+1){
                trace[i][j] = 2;
                t -= 2;
            }
            else{
                trace[i][j] = 1;
                t--;
            }
            s--;
        }
    }
    
    if (!flag){
        return {-1};
    }
    
    for (int s: sequence){
        answer.push_back(trace[s][seqIndex[s]]);
        seqIndex[s]++;
    }
    
    return answer;
}