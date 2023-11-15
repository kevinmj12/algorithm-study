#include <iostream>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;
    long long length[N];
    long long sum = 0;
    for (int i = 0; i < N; i++){
        long long n;
        cin >> n;
        length[i] = n;
        sum += n;
    }
    long long x = sum / K;
    long long low = 0; long long high = x;
    long long answer;
    
    while (true){
        long long y = 0;
        for (int i = 0; i < N; i++){
            y += (length[i] / x);
        }
        if (y >= K){
            low = x;
            x = (low + high) / 2;
            if (x == low){
                cout << x;
                break;
            }
        }
        else{
            high = x;
            x = (low + high) / 2;
        }
    }
}