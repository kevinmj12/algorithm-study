#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int numLength = 1;
    int standard = 9;
    int answer = 0;

    while (n >= standard){
        n -= standard;
        answer += numLength * standard;
        numLength++;
        standard *= 10;
    }
    answer += n * numLength;
    cout << answer;
}