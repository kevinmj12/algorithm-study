#include <iostream>
#include <algorithm>
using namespace std;

int nums[100000];


int main(){
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int left = 0, right = 0, sum = nums[0];
    int answer = 100001;

    while (right < n){
        // 부분합이 s보다 큰 경우
        if (sum >= s){
            answer = min(answer, right-left+1);
            // 1개만으로 s보다 큰 경우
            if (left == right){
                break;
            }
            else{
                sum -= nums[left];
                left++;
            }
        }
        // 부분합이 s보다 작은 경우
        else{
            right++;
            if (right >= n){
                break;
            }
            else{
                sum += nums[right];
            }
        }
    }

    if (answer == 100001){
        cout << 0;
    }
    else{
        cout << answer;
    }
}
