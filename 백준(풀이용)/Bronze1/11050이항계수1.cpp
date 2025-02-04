#include <iostream>

int bm(int a, int b);

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int answer = bm(N, K) / bm(K, K);
    printf("%d", answer);
}

int bm(int a, int b){
    if (a == 0){
        return 1;
    }
    else if (b == 0){
        return 1;
    }
    else{
        return (a * bm(a-1, b-1));
    }
}