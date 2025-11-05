#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    queue<string> q;
    q.push(T);

    int answer = 0;
    while (!q.empty()){
        string str = q.front();
        q.pop();

        if (str == S){
            answer = 1;
            break;
        }

        // 문자열 뒤에 A를 추가했던 경우
        if (str.back() == 'A'){
            q.push(str.substr(0, str.length()-1));
        }
        // 문자열 뒤에 B를 추가하고 뒤집었던 경우
        if (str[0] == 'B'){
            str = str.substr(1);
            reverse(str.begin(), str.end());
            q.push(str);
        }
    }

    cout << answer;
    return 0;
}