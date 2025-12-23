#include <iostream>
#include <algorithm>
using namespace std;
#define ull unsigned long long

ull roads[100001];
ull oil[100001];

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++){
        cin >> roads[i];
    }

    for (int i = 0; i < N; i++){
        cin >> oil[i];
    }

    ull minOil = oil[0];
    ull answer = 0;

    for (int city = 0; city < N-1; city++){
        answer += roads[city] * minOil;
        minOil = min(minOil, oil[city+1]);
    }

    cout << answer;
}
