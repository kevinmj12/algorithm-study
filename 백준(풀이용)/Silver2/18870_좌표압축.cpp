#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> numArr1;
    vector<int> numArr2;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;

        numArr1.push_back(x);
        numArr2.push_back(x);
    }

    sort(numArr1.begin(), numArr1.end());
    numArr1.erase(unique(numArr1.begin(), numArr1.end()), numArr1.end());
    for (int i = 0; i < N; i++){
        cout << lower_bound(numArr1.begin(), numArr1.end(), numArr2[i]) - numArr1.begin() << " ";
    }
}