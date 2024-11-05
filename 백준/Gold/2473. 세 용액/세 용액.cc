#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> liquids;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        long long liquid;
        cin >> liquid;
        liquids.push_back(liquid);
    }

    sort(liquids.begin(), liquids.end());


    long long answerVal = 3000000000;
    vector<int> answer;

    for (int i = 0; i < liquids.size()-2; i++){
        int left = i+1;
        int right = n-1;

        while (left < right){
            long long val = liquids[i] + liquids[left] + liquids[right];
            if (answerVal > abs(val)){
                answerVal = abs(val);
                answer = {i, left, right};
            }

            if (val < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++){
        cout << liquids[answer[i]] << " ";
    }
}