#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    map<int, pair<int, int>> numMap;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;

        if (numMap.find(a) != numMap.end()){
            numMap[a].first++;
        }
        else{
            numMap[a] = {1, N-i};
        }
    }

    vector<pair<int, pair<int, int>>> v(numMap.begin(), numMap.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].second.first; j++){
            cout << v[i].first << " ";
        }
    }
}