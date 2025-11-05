#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    vector<int> numCnt(100001);

    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    int left = 0, right = 1;
    int answer = 1;
    numCnt[numbers[0]]++;

    while (right < N){
        numCnt[numbers[right]]++;

        if (numCnt[numbers[right]] > K){
            while (numbers[left] != numbers[right]){
                numCnt[numbers[left]]--;
                left++;
            }
            numCnt[numbers[left]]--;
            left++;
        }
        answer = max(answer, right - left + 1);

        right++;
    }

    cout << answer;
}