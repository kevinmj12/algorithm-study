#include <iostream>
#include <cmath>
using namespace std;

long long counts[11][10];
long long answer[10];

void solve(int n){
    string str = to_string(n);
    int length = str.length();
    
    int d = pow(10, length-1);
    int q = n / d;

    // 1번째 자리 처리
    for (int i = 1; i < q; i++){
        answer[i] += d;
    }
    answer[q] += (n % d) + 1;

    // 2 ~ L-1번째 자리 처리
    int index = 1;
    d /= 10;
    for (index; index < length-1; index++){
        int target = str[index] - '0';
        int left = stoi(str.substr(0, index));
        int right = stoi(str.substr(index+1));

        // target이 0인 경우
        if (target == 0){
            answer[0] += (left-1) * d + right+1;
            for (int i = target+1; i <= 9; i++){
                answer[i] += left * d;
            }
            d /=10;
            continue;
        }
        // 0
        if (0 < target){
            answer[0] += left * d;
        }
        // 1 ~ target-1
        for (int i = 1; i < target; i++){
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
        
        answer[0] += left;
        for (int i = 1; i <= target; i++){
            answer[i] += left+1;
        }
        for (int i = target+1; i <= 9; i++){
            answer[i] += left;
        }
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
