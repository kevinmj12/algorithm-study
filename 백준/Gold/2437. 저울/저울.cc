#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weights[1000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights, weights+n);

    int answer = 0;

    if (weights[0] != 1){
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (weights[i] <= answer+1){
            answer += weights[i];
        }
        else{
            break;
        }
    }
    cout << answer+1;
}