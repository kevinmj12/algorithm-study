#include <iostream>
#include <algorithm>
using namespace std;

int visitors[250001];

int main(){
    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; i++){
        cin >> visitors[i];
    }

    int left = 0;
    int right = X-1;
    int total = 0;

    for (int i = left; i <= right; i++){
        total += visitors[i];
    }
    int answer = total;
    int answerPeriod = 1;

    while (right < N){
        total -= visitors[left];
        left++;
        right++;
        total += visitors[right];

        if (total > answer){
            answer = total;
            answerPeriod = 1;
        }
        else if (total == answer){
            answerPeriod++;
        }    
    }


    if (answer == 0){
        cout << "SAD";
    }
    else{
        cout << answer << "\n" << answerPeriod;
    }
}