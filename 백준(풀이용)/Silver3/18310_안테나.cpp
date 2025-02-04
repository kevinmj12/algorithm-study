#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> houses;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int house;
        cin >> house;
        houses.push_back(house);
    }
    sort(houses.begin(), houses.end());
    cout << houses[(houses.size()-1)/2];
}