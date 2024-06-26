#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long double periods[10001][2];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> periods[i][0] >> periods[i][1];
    }
    periods[n][0] = periods[0][0];
    periods[n][1] = periods[0][1];
    
    long double answer = 0;

    cout << fixed;
    cout.precision(1);
    // 신발끈 공식으로 넓이 구하기
    for (int i = 0; i < n; i++){
        pair<long long, long long> period1 = {periods[i][0], periods[i][1]};
        pair<long long, long long> period2 = {periods[i+1][0], periods[i+1][1]};

        long double area = ((period1.first * period2.second)-(period2.first * period1.second));
        answer += area;
    }

    cout << abs(answer)/2;
}