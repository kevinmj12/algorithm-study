#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> liquids;
vector<pair<int, int>> twoLiquids;

int binarySearch(int n, long long target){
    int left = 0;
    int right = n-1;
    target *= -1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (liquids[mid] == target){
            return mid;
        }
        if (liquids[mid] < target){
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return left;
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        long long liquid;
        cin >> liquid;
        liquids.push_back(liquid);
    }

    sort(liquids.begin(), liquids.end());

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            twoLiquids.push_back({i, j});
        }
    }

    long long answerVal = 3000000000;
    vector<int> answer;

    for (int i = 0; i < twoLiquids.size(); i++){
        int a = twoLiquids[i].first;
        int b = twoLiquids[i].second;
        long long val = liquids[a]+liquids[b];

        int trg = binarySearch(n, val);
        
        if ((trg < n && trg != a && trg != b)){
            if (answerVal > abs(val + liquids[trg])){
                answerVal = abs(val + liquids[trg]);
                answer = {a, b, trg};
            }
        }
        trg--;
        if ((trg >= 0 && trg != a && trg != b)){
            if (answerVal > abs(val + liquids[trg])){
                answerVal = abs(val + liquids[trg]);
                answer = {a, b, trg};
            }
        }
    }

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++){
        cout << liquids[answer[i]] << " ";
    }
}