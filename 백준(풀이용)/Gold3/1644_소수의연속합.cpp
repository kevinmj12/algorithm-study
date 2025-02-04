#include <iostream>
#include <vector>
using namespace std;

bool isPrime[4000001];
vector<int> primeNum;

void getPrime(int n){
    for (int i = 2; i <= n; i++){
        isPrime[i] = true;
    }

    for (int index = 2; index <= n; index++){
        if (!isPrime[index]){
            continue;
        }
        primeNum.push_back(index);
        int i = 2;
        while (index * i <= n){
            isPrime[index*i] = false;
            i++;
        }
    }
}

int solve(int n){
    int answer = 0;
    int sum = 2;

    int left = 0, right = 0;
    while (right < primeNum.size()){
        // 합이 n보다 작은 경우
        if (sum < n){
            if (right+1 < primeNum.size()){
                right++;
                sum += primeNum[right];
            }
            else{
                return answer;
            }
        }
        // 합이 n과 같은 경우
        else if (sum == n){
            answer++;
            sum -= primeNum[left];
            left++;
        }
        // 합이 n보다 큰 경우
        else{
            sum -= primeNum[left];
            left++;
        }
    }

    return answer;
}

int main(){
    int n;
    cin >> n;

    getPrime(n);

    cout << solve(n);
}