#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long pow(long long n, long long m) {
	long long rtn = 1;
	while (m) {
		if (m & 1) {
            rtn = rtn * n % MOD;
        }
		m = m / 2;
		n = n * n % MOD;
	}
	return rtn;
}

int main(){
    int m;
    cin >> m;

    long long answer = 0;
    while (m--){
        int n, s;
        cin >> n >> s;
        
        int g = __gcd(n, s);
        n /= g;
        s /= g;

        answer += s * (pow(n, MOD - 2));
        answer %= MOD;
    }

    cout << answer;
}