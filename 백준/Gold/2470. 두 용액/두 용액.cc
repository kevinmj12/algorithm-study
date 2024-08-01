#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> liquids;

    for (int i = 0; i < n; i++){
        int liquid;
        cin >> liquid;
        
        liquids.push_back(liquid);
    }

    sort(liquids.begin(), liquids.end());

    int left = 0, right = liquids.size()-1;
    int answer1, answer2;
    int val = 2000000001;
    
    while (left < right){
        int tmp = abs(liquids[left]+liquids[right]);
        if (tmp < val){
            val = tmp;
            answer1 = liquids[left];
            answer2 = liquids[right];
        }

        if (liquids[left]+liquids[right] > 0){
            right--;
        }
        else{
            left++;
        }
    }
    cout << answer1 << " " << answer2;
}