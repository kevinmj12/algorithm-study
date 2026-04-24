#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    stack<pair<int, int>> s;
    for (int i = 0; i < numbers.size(); i++){
        while (!s.empty() && numbers[i] > s.top().first){
            answer[s.top().second] = numbers[i];
            s.pop();
        }
        s.push({numbers[i], i});
    }
    
    return answer;
}