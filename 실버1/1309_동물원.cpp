#include <iostream>
using namespace std;
#define MAX 100001
#define DIVIDER 9901

int noLion[MAX];
int lion[MAX];

int main(){
    int N;
    cin >> N;

    // base case
    noLion[1] = 1;
    lion[1] = 2;

    for (int i = 2; i <= N; i++){
        noLion[i] = (noLion[i-1] + lion[i-1])%DIVIDER;
        lion[i] = (noLion[i-1]*2 + lion[i-1])%DIVIDER;
    }

    cout << (noLion[N] + lion[N])%DIVIDER;
}