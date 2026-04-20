#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer = {0, 0};
    int maxDate = 0;
    
    int INF = 500002;
    vector<int> rain(m*n, INF);
    
    for (int i = 0; i < drops.size(); i++){
        int r = drops[i][0];
        int c = drops[i][1];
        rain[r*n + c] = i+1;
    }
    
    int newN = n - w + 1;
    vector<int> minRow(m * newN);
    
    for (int r = 0; r < m; r++){
        deque<int> dq;
        for (int c = 0; c < n; c++){
            while (!dq.empty() && rain[r*n + dq.back()] > rain[r*n + c]){
                dq.pop_back();
            }
            
            dq.push_back(c);
            
            if (dq.front() == c - w){
                dq.pop_front();
            }
            
            if(c >= w - 1){
                minRow[r * newN + (c - w + 1)] = rain[r*n + dq.front()];
            }
        }
    }
    
    for (int c = 0; c < newN; c++){
        deque<int> dq;
        for (int r = 0; r < m; r++){
            int minRowVal = minRow[r*newN + c];
            while (!dq.empty() && minRow[dq.back()*newN + c] > minRowVal){
                dq.pop_back();
            }
            
            dq.push_back(r);
            
            if (dq.front() == r - h){
                dq.pop_front();
            }
            
            
            
            if (r >= h - 1){
                int maxValIdx = dq.front()*newN + c;
                if (minRow[maxValIdx] > maxDate){
                    answer = {r-h+1, c};
                    maxDate = minRow[maxValIdx];
                }
                else if (minRow[maxValIdx] == maxDate){
                    if (r-h+1 < answer[0] ||
                       r-h+1 == answer[0] && c < answer[1]){
                        answer = {r-h+1, c};
                        maxDate = minRow[maxValIdx];    
                    }
                }
            }
        }
    }    
    
    return answer;
}