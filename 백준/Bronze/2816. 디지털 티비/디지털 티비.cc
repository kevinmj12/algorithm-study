#include <iostream>
#include <string>
using namespace std;


string channels[101];

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> channels[i];
    }

    string answer = "";

    // KBS1
    int cur = 1;
    while (channels[cur] != "KBS1"){
        cur++;
        answer += '1';
    }
    
    int cnt = cur-1;
    for (int i = 0; i < cnt; i++){
        swap(channels[cur], channels[cur-1]);
        cur--;
        answer += '4';
    }
    
    // KBS2
    while (channels[cur] != "KBS2"){
        cur++;
        answer += '1';
    }
    cnt = cur-2;
    for (int i = 0; i < cnt; i++){
        answer += '4';
    }

    cout << answer;
}