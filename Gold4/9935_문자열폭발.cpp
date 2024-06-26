#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
    string str, target;
    cin >> str;
    cin >> target;

    stack<char> answer;
    stack<char> targets;

    for (int i = 0; i < str.length(); i++){
        char c = str[i];
        if (c == target[target.length()-1] && (answer.size() >= target.length()-1)){
            targets.push(c);

            int j = target.length()-2;
            
            while (j >= 0 && target[j] == answer.top()){
                targets.push(answer.top());
                answer.pop();
                j--;
            }
            if (targets.size() == target.length()){
                while(!targets.empty()){
                    targets.pop();
                }
            }
            else{
                while(!targets.empty()){
                    answer.push(targets.top());
                    targets.pop();
                }
            }
        }
        else{
            answer.push(c);
        }
    }
    stack<char> answer2;
    while (!answer.empty()){
        answer2.push(answer.top());
        answer.pop();
    }
    if (answer2.empty()){
        cout << "FRULA";
    }
    else{
        while (!answer2.empty()){
            cout << answer2.top();
            answer2.pop();
        }
    }
}