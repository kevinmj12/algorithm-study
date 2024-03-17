#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string str);
string transform(string str);
int cal(string str);

void make(string str, int idx){
    if (idx+1 < str.length()){
        string s1 = str.substr(0, idx+1)+"*"+str.substr(idx+1);
        string s2 = str.substr(0, idx+1)+"+"+str.substr(idx+1);
        string s3 = str.substr(0, idx+1)+"-"+str.substr(idx+1);
        string s4 = str;

        make(s1, idx+2);
        check(s1);

        make(s2, idx+2);
        check(s2);

        make(s3, idx+2);
        check(s3);

        make(s4, idx+1);

    }
}

bool check(string str){
    for (int i = 0; i < str.length(); i++){
        if (str[i] != '0'){
            i++;
            while ('0' <= str[i] && str[i] <= '9'){
                i++;
            }
        }
        else{
            if ('0' <= str[i+1] && str[i+1] <= '9'){
                return false;
            }
            else{
                i++;
            }
        }
    }
    int answer = cal(transform(str));
    if (cal(transform(str)) == 2000){
        cout << str <<"\n";
    }
    return true;
}

string transform(string str){
    stack<char> s;
    string newStr = "";

    for (int i = 0; i < str.length(); i++){
        if (str[i] == '+' || str[i] == '-'){
            while (!s.empty()){
                newStr += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == '*'){
            if (!s.empty() && s.top() == '*'){
                newStr += s.top();
            }
            else{
                s.push('*');
            }
        }
        else{
            newStr += '(';
            newStr += str[i];
            while ('0' <= str[i+1] && str[i+1] <= '9'){
                newStr += str[i+1];
                i++;
            }
            newStr += ')';
        }
    }

    while (!s.empty()){
        newStr += s.top();
        s.pop();
    }

    return newStr;
}

int cal(string str){
    stack<int> s;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == '+'){
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            s.push(a+b);
        }
        else if (str[i] == '-'){
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            s.push(b-a);
        }
        else if (str[i] == '*'){
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            s.push(a*b);
        }
        // (123) 과 같이 숫자가 들어오는경우
        else{
            i++;
            int tmpNum = str[i]-'0';

            while (str[i+1] != ')'){
                tmpNum *= 10;
                tmpNum += str[i+1]-'0';
                i++;
            }

            s.push(tmpNum);
            i++;
        }

    }
    return s.top();
}

int main(){
    string input;
    cin >> input;

    make(input, 0);
}