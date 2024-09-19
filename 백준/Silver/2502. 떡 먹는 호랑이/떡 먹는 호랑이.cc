#include <iostream>
#include <vector>
using namespace std;

pair<int, int> arr[31];

int main(){
    int d, k;
    cin >> d >> k;

    arr[1] = {1, 0};
    arr[2] = {0, 1};
    for (int i = 3; i <= d; i++){
        arr[i] = {arr[i-2].first+arr[i-1].first, arr[i-2].second+arr[i-1].second};
    }

    int a = 1;
    while (true){
        if ((k - arr[d].first * a) % arr[d].second == 0){
            cout << a << "\n";
            cout << (k - arr[d].first * a) / arr[d].second;
            return 0;
        }
        a++;
    }
}