#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

bool visited[1000001];

int backtracking(int x, int y, int n){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    int cnt = 0;
    while (!q.empty()){
        int size = q.size();
        for (int s = 0; s < size; s++){
            int a = q.front();
            q.pop();
            
            if (a == y){
                return cnt;
            }
            
            if (a*3 <= y && !visited[a*3]){
                q.push(a*3);
                visited[a*3] = true;
            }
            if (a*2 <= y && !visited[a*2]){
                q.push(a*2);
                visited[a*2] = true;
            }
            if (a+n <= y && !visited[a+n]){
                q.push(a+n);
                visited[a+n] = true;
            }
        }
        cnt++;
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
        
    answer = backtracking(x, y, n);
    
    return answer;
}