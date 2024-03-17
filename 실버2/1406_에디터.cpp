#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    stack<char> cursorLeft;
    stack<char> cursorRight;

    // input을 받음
    string input;
    cin >> input;

    // input을 cursorLeft에 넣어줌
    for (char c : input){
        cursorLeft.push(c);
    }

    // 명령을 입력받음
    int orders;
    cin >> orders;

    while (orders--){
        char order;
        cin >> order;

        if (order == 'L'){
            if (!cursorLeft.empty()){
                cursorRight.push(cursorLeft.top());
                cursorLeft.pop();
            }
        }
        else if (order == 'D'){
            if(!cursorRight.empty()){
                cursorLeft.push(cursorRight.top());
                cursorRight.pop();
            }
        }
        else if (order == 'B'){
            if (!cursorLeft.empty()){
                cursorLeft.pop();
            }
        }
        else{
            char c;
            cin >> c;
            cursorLeft.push(c);
        }
    }

    // answer를 출력함
    while (!cursorLeft.empty()){
        cursorRight.push(cursorLeft.top());
        cursorLeft.pop();
    }

    // right에 있는 원소 출력
    while (!cursorRight.empty()){
        cout << cursorRight.top();
        cursorRight.pop();
    }

}