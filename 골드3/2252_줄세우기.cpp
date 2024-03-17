#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAX 32001

vector<int> graph[MAX];
int tallStudent[MAX];
bool visited[MAX];
int n, m;
stack<int> answer;


void Reset(){
    for (int i = 1; i <= n; i++){
        tallStudent[i] = 0;
    }
}

void TopologySort(){
    queue<int> students;
    for (int i = 1; i <= n; i++){
        if (!tallStudent[i]){
            students.push(i);
        }
    }
    
    while (!students.empty()){
        int present = students.front();
        answer.push(present);
        students.pop();

        for (int i = 0; i < graph[present].size(); i++){
            int next = graph[present][i];
            tallStudent[next]--;
            if (!tallStudent[next]){
                students.push(next);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    Reset();
    
    for (int i = 0; i < m; i++){
        int h1, h2;
        cin >> h1 >> h2;

        graph[h2].push_back(h1);
        tallStudent[h1]++;
    }

    TopologySort();

    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
}