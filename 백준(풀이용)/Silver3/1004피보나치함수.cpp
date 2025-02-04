#include <iostream>
#include <vector>

int fiboZero[41];
int fiboOne[41];

std::pair<int, int> fibo(int n){
    int zero = fiboZero[n-1]+fiboZero[n-2];
    int one = fiboOne[n-1]+fiboOne[n-2];

    return (std::make_pair(zero, one));
}

int main(){
    fiboZero[0] = 1; fiboZero[1] = 0;
    fiboOne[0] = 0; fiboOne[1] = 1;
    for (int i = 2; i < 41; i++){
        std::pair<int, int> tmp = fibo(i);
        fiboZero[i] = tmp.first;
        fiboOne[i] = tmp.second;
    }
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);
        printf("%d %d\n", fiboZero[N], fiboOne[N]);
    }
}