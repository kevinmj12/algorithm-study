#include <iostream>
#include <vector>
using namespace std;
#define PRIME_MAX 1000000
typedef long long ll;

bool isPrime[PRIME_MAX+1];
vector<ll> primeNumber;
bool targets[PRIME_MAX+1];

int main(){
    ll min, max;
    cin >> min >> max;

    for (int i = 0; i <= PRIME_MAX; i++){
        isPrime[i] = true;
        targets[i] = true;
    }
    // 소수 찾기
    for (int i = 2; i <= PRIME_MAX; i++){
        if (isPrime[i]){
            primeNumber.push_back(i);
            int end = PRIME_MAX/i;
            for (int j = 1; j <= end; j++){
                isPrime[i * j] = false;
            }
        }
    }

    // 제곱ㄴㄴ수 찾기
    for (ll p : primeNumber){
        ll pp = p * p;
        if (pp > max){
            break;
        }

        ll left = min/pp;
        if (min % pp){
            left++;
        }
        
        while (left * pp <= max){
            targets[left*pp-min] = false;
            left++;
        }
    }

    int answer = 0;
    for (int i = 0; i <= max-min; i++){
        if (targets[i]){
            answer++;
        }
    }

    cout << answer;
}

