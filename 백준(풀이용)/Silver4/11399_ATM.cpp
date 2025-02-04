#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> times;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        times.push_back(tmp);
    }

    sort(times.begin(), times.end());

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += (n-i)*times[i];
    }

    cout << sum;
}