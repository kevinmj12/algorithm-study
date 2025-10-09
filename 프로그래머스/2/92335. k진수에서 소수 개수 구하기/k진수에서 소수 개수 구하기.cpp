#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string pStr = "";
    while (n > 0) {
        pStr += to_string(n % k);
        n /= k;
    }
    reverse(pStr.begin(), pStr.end());

    int left = 0;
    for (int i = 0; i <= pStr.length(); i++) {
        if (i == pStr.length() || pStr[i] == '0') {
            if (i > left) {
                long long p = stoll(pStr.substr(left, i - left));
                if (isPrime(p)) answer++;
            }
            left = i + 1;
        }
    }

    return answer;
}
