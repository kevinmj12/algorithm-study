#include <iostream>

using namespace std;

int main(){
    int son, mom, N;
    cin >> son >> mom >> N;
    int answer;
    for (int i = 0; i < N+1; i++){
        answer = son / mom;
        son = son % mom * 10;
    }

    cout << answer;
}