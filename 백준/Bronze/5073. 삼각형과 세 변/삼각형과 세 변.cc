#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true){
        vector<int> nums(3, 0);
        cin >> nums[0] >> nums[1] >> nums[2];

        if (nums[0] == 0 && nums[0] == nums[1] && nums[1] == nums[2]){
            return 0;
        }

        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]){
            cout << "Invalid\n";
        }
        else if (nums[0] == nums[1] && nums[1] == nums[2]){
            cout << "Equilateral\n";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2]){
            cout << "Isosceles\n";
        }
        else{
            cout << "Scalene\n";
        }
    }
}