#include <iostream>
#include <algorithm>
using namespace std;

int liquids[100000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> liquids[i];
    }

    int left = 0, right = n-1;

    int answer = liquids[left]+liquids[right];
    while (left < right){
        int tmp = liquids[left] + liquids[right];
        if (abs(tmp) < abs(answer)){
            answer = tmp;
        }

        if (tmp > 0){
            right--;
        }
        else{
            left++;
        }
    }

    cout << answer;
}