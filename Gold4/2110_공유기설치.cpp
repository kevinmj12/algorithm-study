#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> houses;

int main(){
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++){
        int house;
        cin >> house;

        houses.push_back(house);
    }

    sort(houses.begin(), houses.end());

    int left = 1;
    int right = houses[n-1]-houses[0];
    int answer;
    while (left <= right){
        int mid = (left+right)/2;
        int cur = houses[0];
        int cnt = 1;

        for (int i = 1; i < n; i++){
            if (houses[i]-cur >= mid){
                cur = houses[i];
                cnt++;
            }
        }

        if (cnt >= c){
            answer = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    cout << answer;
}