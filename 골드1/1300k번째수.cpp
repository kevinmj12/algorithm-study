#include <iostream>

int N, k;

long long func(int num){
    long long countNum = 0;
    for (int i = 1; i <= N; i++){
        if (N <= num/i){
            countNum += N;
        }
        else{
            countNum += (num / i);
        }
    }
    return countNum;
}

int foundK(){
    int left = 0;
    int right;
    int mid;
    if (N >= 31623){ // 31623^2 > 10^9
        right = 1000000000;
    }
    else{
        right = N * N;
    }
    while (left < right){
        mid = (left + right) / 2;
        long long cnt = func(mid);
        if (k > cnt){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main(){
    scanf("%d", &N);
    scanf("%d", &k);
    printf("%d", foundK());
}