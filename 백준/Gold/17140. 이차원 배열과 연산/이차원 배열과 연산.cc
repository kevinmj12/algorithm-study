#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#define MAX INT_MAX
using namespace std;

int arr[200][200];
int rows = 3;
int columns = 3;

void solve(){
    int maxI, maxJ;
    bool isRow = true;
    vector<vector<int>> newArr;

    if (rows >= columns){
        for (int i = 1; i <= rows; i++){
            map<int, int> numCnt;
            vector<vector<int>> vec;
    
            // 조건에 맞게 vec에 넣기
            for (int j = 1; j <= columns; j++){
                if (arr[i][j]){
                    numCnt[arr[i][j]]++;
                }
            }
            for (auto it = numCnt.begin(); it != numCnt.end(); it++){
                int key = it->first;
                int val = it->second;
                vec.push_back({val, key}); // {등장횟수, 수}
            }
            // 정렬
            sort(vec.begin(), vec.end());
            
            // 정렬한 값을 newArr에 1차로 넣음
            newArr.push_back({});
            for (int j = 1; j <= vec.size(); j++){
                newArr[i-1].push_back(vec[j-1][1]);
                newArr[i-1].push_back(vec[j-1][0]);
            }
            
            int size = vec.size() * 2;
            columns = max(columns, size);
        }
        // newArr 값을 arr로 업데이트
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= newArr[i-1].size(); j++){
                arr[i][j] = newArr[i-1][j-1];
            }
            for (int j = newArr[i-1].size()+1; j <= columns; j++){
                arr[i][j] = 0;
            }
        }
    }
    else{
        for (int i = 1; i <= columns; i++){
            map<int, int> numCnt;
            vector<vector<int>> vec;
    
            // 조건에 맞게 vec에 넣기
            for (int j = 1; j <= rows; j++){
                if (arr[j][i]){
                    numCnt[arr[j][i]]++;
                }
            }
            for (auto it = numCnt.begin(); it != numCnt.end(); it++){
                int key = it->first;
                int val = it->second;
                vec.push_back({val, key}); // {등장횟수, 수}
            }
            // 정렬
            sort(vec.begin(), vec.end());
            
            // 정렬한 값을 newArr에 1차로 넣음
            newArr.push_back({});
            for (int j = 1; j <= vec.size(); j++){
                newArr[i-1].push_back(vec[j-1][1]);
                newArr[i-1].push_back(vec[j-1][0]);
            }
            
            int size = vec.size() * 2;
            rows = max(rows, size);
        }
        // newArr 값을 arr로 업데이트
        for (int i = 1; i <= columns; i++){
            for (int j = 1; j <= newArr[i-1].size(); j++){
                arr[j][i] = newArr[i-1][j-1];
            }
            for (int j = newArr[i-1].size()+1; j <= rows; j++){
                arr[j][i] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    while (cnt <= 100 && arr[r][c] != k){
        solve();
        cnt++;
    }

    if (cnt > 100){
        cout << -1;
    }
    else{
        cout << cnt;
    }
}