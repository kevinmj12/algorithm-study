#include <iostream>
using namespace std;

int money[6] = {500, 100, 50, 10, 5, 1};

int main(){
    int N;
    cin >> N;

    N = 1000 - N;
    int answer = 0;

    for (int i = 0; i < 6; i++){
        answer += N / money[i];
        N %= money[i];
    }

    cout << answer;
}