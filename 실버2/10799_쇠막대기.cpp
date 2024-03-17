#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<int> s;

    string str;
    cin >> str;

    int answer = 0;
    bool laser = false;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '('){
            s.push(0);
            laser = true;
        }
        else if (laser){
            s.pop();
            answer += s.size();
            laser = false;
        }
        else{
            s.pop();
            answer++;
            laser = false;
        }
    }

    cout << answer;
}
