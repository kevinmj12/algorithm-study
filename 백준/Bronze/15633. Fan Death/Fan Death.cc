#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int max = sqrt(n);
    int answer = 0;
    for (int i = 1; i <= max; i++){
        if (n % i == 0){
            int q = n / i;
            answer += i;
            if (q != i){
                answer += q;
            }
        }
    }
    cout << answer * 5 - 24;
}