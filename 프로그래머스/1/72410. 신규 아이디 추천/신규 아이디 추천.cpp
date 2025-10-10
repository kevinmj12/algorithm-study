#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for (int i = 0; i < new_id.length(); i++){
        char& c = new_id[i];
        // 1) 소문자 치환
        if ('A' <= c && c <= 'Z'){
            c += 32;
        }
        // 2) 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표 제외 문자 제거
        if (!(('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '-' || c == '_' || c == '.')){
            new_id = new_id.substr(0, i) + new_id.substr(i+1);
            i--;
        }
    }
    
    // 3) 연속되는 마침표 제거
    bool point = false;
    for (int i = 0; i < new_id.length(); i++){
        char& c = new_id[i];
        if (c == '.'){
            if (point){
                new_id = new_id.substr(0, i) + new_id.substr(i+1);
                i--;
            }
            else{
                point = true;
            }
        }
        else{
            point = false;
        }
    }
    
    // 4) 처음과 끝에 위치한 마침표 제거
    if (new_id[0] == '.'){
        new_id = new_id.substr(1);
    }
    if (new_id[new_id.length()-1] == '.'){
        new_id = new_id.substr(0, new_id.length()-1);
    }
    
    // 5) 빈 문자열이라면 a 대입
    if (new_id.length() == 0){
        new_id = "a";
    }
    
    // 6) 16자 이상이면 첫 15개 문자를 제외한 문자들 제거, 마침표가 끝에 위치한다면 제거
    if (new_id.length() >= 16){
        new_id = new_id.substr(0, 15);
    }
    if (new_id[new_id.length()-1] == '.'){
        new_id = new_id.substr(0, new_id.length()-1);
    }
    
    // 7) 2자 이하라면 마지막 문자를 길이가 3이 될 때까지 반복해서 붙임
    while (new_id.length() < 3){
        new_id += new_id[new_id.length()-1];
    }
    
    answer = new_id;
    
    return answer;
}