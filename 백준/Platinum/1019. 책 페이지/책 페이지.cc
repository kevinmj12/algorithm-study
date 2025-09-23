#include <iostream>
#include <cmath>
using namespace std;

int answer[10];

void solve(int n){
    string str = to_string(n);
    int length = str.length();
    
    // 1번째 자리 처리
    int d = pow(10, length-1);
    int q = n / d;

    // 0 ~ target-1
    for (int i = 0; i < q; i++){
        answer[i] += d;
    }

    // target
    answer[q] += (n % d) + 1;

    // 2 ~ L-1번째 자리 처리
    int index = 1;
    d /= 10;
    for (index; index < length-1; index++){
        int target = str[index] - '0';
        int left = stoi(str.substr(0, index));
        int right = stoi(str.substr(index+1));

        // 0 ~ target-1
        for (int i = 0; i < target; i++){
            answer[i] += (left+1) * d;
        }
        
        // target
        answer[target] += left * d + right+1;

        // target+1 ~ 9
        for (int i = target+1; i <= 9; i++){
            answer[i] += left * d;
        }

        d /= 10;
    }

    // L번째 자리 처리 (한 자리 수의 경우, 처리하면 안됨)
    if (length != 1){
        int target = str[index] - '0';
        int left = stoi(str.substr(0, index));
        
        // 0 ~ target
        for (int i = 0; i <= target; i++){
            answer[i] += left+1;
        }

        // target+1 ~ 9
        for (int i = target+1; i <= 9; i++){
            answer[i] += left;
        }
    }
    
    // 0 제거 작업
    d = pow(10, length-1);
    for (int i = 0; i < length; i++){
        answer[0] -= d;
        d /= 10;
    }

    for (int i = 0; i <= 9; i++){
        cout << answer[i] << " ";
    }
}

int main(){
    int N;
    cin >> N;

    solve(N);
}