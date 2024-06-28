#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long nums[4000][4];
vector<long long> abSum;
vector<long long> cdSum;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
    }
    
    // a와b의 합, c와d의 합을 저장
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            abSum.push_back(nums[i][0]+nums[j][1]);
            cdSum.push_back(nums[i][2]+nums[j][3]);
        }
    }
    // 정렬
    sort(abSum.begin(), abSum.end());
    sort(cdSum.begin(), cdSum.end());
    // a와b의합은 가장 작은 값부터 시작(인덱스 0)
    // 위를 기반으로 c와d의 합 인덱스를 이진탐색
    int abIndex = 0, cdIndex = cdSum.size()-1;
    // int left = 0, right = cdSum.size()-1;
    // while (left < right){
    //     cdIndex = (left+right)/2;
    //     if (cdSum[cdIndex] + abSum[abIndex] >= 0){
    //         right = cdIndex;
    //     }
    //     else{
    //         left = cdIndex+1;
    //     }
    // }
    // cdIndex = (left+right)/2;

    // 투 포인터로 합이 0인 조합을 찾음
    long long answer = 0;
    while (abIndex < abSum.size() && cdIndex >= 0){
        if (abSum[abIndex] + cdSum[cdIndex] == 0){
            long long abCnt = 1, cdCnt = 1;
            while (abIndex+1 < abSum.size() && abSum[abIndex] == abSum[abIndex+1]){
                abIndex++;
                abCnt++;
            }
            while (cdIndex-1 >= 0 && cdSum[cdIndex] == cdSum[cdIndex-1]){
                cdIndex--;
                cdCnt++;
            }
            answer += abCnt * cdCnt;
            cdIndex--;
        }
        else if (abSum[abIndex] + cdSum[cdIndex] < 0){
            abIndex++;
        }
        else{
            cdIndex--;
        }
    }
    cout << answer;
}