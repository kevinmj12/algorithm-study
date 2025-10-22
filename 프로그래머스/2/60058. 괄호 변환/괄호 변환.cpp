#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 올바른 문자열인지 확인하는 함수
bool isRight(string p){
    int left = 0, right = 0;
    bool flag = true;
    for (int i = 0; i < p.length(); i++){
        if (p[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if (right > left){
            flag = false;
            break;
        }
    }
    return flag;
}

string solve(string p){
    // 1
    if (p == ""){
        return p;
    }
    // 2
    int i;
    int left = 0, right = 0;
    for (i = 0; i < p.length(); i++){
        if (p[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if (left == right){
            break;
        }
    }
    string u = p.substr(0, i+1);
    string v = p.substr(i+1);
    
    // 3
    if (isRight(u)){
        return u + solve(v);
    }
    // 4
    string rtn = "(";
    rtn += solve(v);
    rtn += ")";
    
    string newU = "";
    for (int j = 1; j < u.length() - 1; j++){
        newU += u[j] == '(' ? ')' : '(';
    }
    return rtn + newU;
}

string solution(string p) {
    string answer = "";
    
    // 이미 올바른 괄호 문자열인 경우
    if (isRight(p)){
        return p;
    }
    
    answer = solve(p);
    
    return answer;
}