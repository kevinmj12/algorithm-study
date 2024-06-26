#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // n!을 소인수분해하여 5의 개수를 셈
    // 5의 개수가 곧 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지의 개수임
    int countFive = 0;
    for (int i = 1; i <= n; i++){
        int k = i;
        while (!(k % 5)){
            countFive++;
            k /= 5;
        }
    }

    cout << countFive;
}