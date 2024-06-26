#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, int> m;

    int K, L;
    cin >> K >> L;

    int order = 1;
    while (L--){
        string studentNumber;
        cin >> studentNumber;

        // 찾지 못한 경우
        if (m.find(studentNumber) == m.end()){
            m.insert({studentNumber, order});
            order++;
        }
        // 찾은 경우
        else{
            m.erase(studentNumber);
            m.insert({studentNumber, order});
            order++;
        }
    }
    
    vector<pair<string, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), cmp);

    int KK = v.size();
    for (int i = 0; i < min(K, KK); i++){
        cout << v[i].first << "\n";
    }
}