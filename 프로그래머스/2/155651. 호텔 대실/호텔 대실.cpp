#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int timeToMin(string t){
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    
    return h*60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> bookTime;
    for (int i = 0; i < book_time.size(); i++){
        int start = timeToMin(book_time[i][0]);
        int end = timeToMin(book_time[i][1]);
        bookTime.push_back({start, end});
    }
    
    sort(bookTime.begin(), bookTime.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < bookTime.size(); i++){
        int start = bookTime[i][0];
        int end = bookTime[i][1] + 10;
        
        while (!pq.empty() && pq.top() <= start){
            pq.pop();
        }
        
        pq.push(end);
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}