#include <iostream>
#include <climits>
using namespace std;

#define MAX 1001
int numArr[MAX];
int increase[MAX];
int decrease[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> numArr[i];
        increase[i] = 1;
        decrease[i] = 1;
    }

    // 증가하는 부분 수열 저장
    for (int i = 2; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (numArr[j] < numArr[i]){
                increase[i] = max(increase[i], increase[j]+1);
            }
        }
    }
    // 감소하는 부분 수열 저장
    for (int i = N-1; i >= 1; i--){
        for (int j = N; j > i; j--){
            if (numArr[j] < numArr[i]){
                decrease[i] = max(decrease[i], decrease[j]+1);
            }
        }
    }

    int answer = 1;
    for (int i = 1; i <= N; i++){
        answer = max(answer, increase[i]+decrease[i]-1);
    }
    cout << answer;
}