#include <iostream>
using namespace std;

int people[1000000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> people[i];
    }

    int b, c;
    cin >> b >> c;

    unsigned long long answer = 0;
    for (int i = 0; i < n; i++){
        if (people[i] > 0){
            people[i] -= b;
            answer++;
        }
        if (people[i] > 0){
            answer += (people[i]-1) / c + 1;
        }
    }

    cout << answer;
}