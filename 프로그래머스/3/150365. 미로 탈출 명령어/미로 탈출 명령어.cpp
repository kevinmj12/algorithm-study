#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int dirChar[4] = {'d', 'l', 'r', 'u'};
int dirs[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

string minPath(int n, int m, int x, int y, int r, int c){
    string path = "";
    if (x < r){
        for (int i = 0; i < r-x; i++){
            path += 'd';
        }
    }
    if (y > c){
        for (int i = 0; i < y-c; i++){
            path += 'l';
        }
    }
    if (y < c){
        for (int i = 0; i < c-y; i++){
            path += 'r';
        }
    }
    if (x > r){
        for (int i = 0; i < x-r; i++){
            path += 'u';
        }
    }
    return path;
}

void moveByP(int& pIndex, string p, string& answer, int& x, int& y, int dir){
    for (pIndex; pIndex < p.length(); pIndex++){
        if (p[pIndex] == dirChar[dir]){
            answer += dirChar[dir];
            x += dirs[dir][0];
            y += dirs[dir][1];
        }
        else{
            return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    string p = minPath(n, m, x, y, r, c);
    int pLen = p.length();
    // 탈출이 불가능한 경우
    if (abs(k - pLen) % 2 || pLen > k){
        return "impossible";
    }
    
    int pIndex = 0;
    
    // p의 d 반영
    moveByP(pIndex, p, answer, x, y, 0);
    
    // d로 최대한 이동
    int needMoveUp = 0;
    while (pLen + needMoveUp*2 < k){
        if (x < n){
            x++;
            answer += 'd';
            needMoveUp++;
        }
        else{
            break;
        }
    }
    // p의 l 반영
    moveByP(pIndex, p, answer, x, y, 1);
    
    // l로 최대한 이동
    int needMoveRight = 0;
    while (pLen + (needMoveUp+needMoveRight) * 2 < k){
        if (y > 1){
            y--;
            answer += 'l';
            needMoveRight++;
        }
        else{
            break;
        }
    }
    
    // r, l 왔다갔다 반복
    while (pLen + (needMoveUp+needMoveRight) * 2 < k){
        answer += 'r';
        answer += 'l';
        k -= 2;
    }
    
    // p의 r 반영
    moveByP(pIndex, p, answer, x, y, 2);
    // needMoveRight만큼 r 이동
    for (int i = 0; i < needMoveRight; i++){
        answer += 'r';
    }
    
    // p의 u 반영
    moveByP(pIndex, p, answer, x, y, 3);
    // needMoveUp만큼 u 이동
    for (int i = 0; i < needMoveUp; i++){
        answer += 'u';
    }
    
    return answer;
}