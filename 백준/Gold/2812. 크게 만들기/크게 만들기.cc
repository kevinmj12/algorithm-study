#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool removeNum[500001];
vector<pair<int, int>> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    stack<char> s;
    
    s.push(str[0]);
    for (int i = 1; i < N; i++){
        if (K == 0){
            s.push(str[i]);
        }
        else{
            if (str[i] > s.top()){
                while (s.size() && K && s.top() < str[i]){
                    s.pop();
                    K--;
                }
            }
            s.push(str[i]);
        }
    }

    for (int i = 0; i < K; i++){
        s.pop();
    }

    string answer = "";
    while (!s.empty()){
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());

    cout << answer;
}