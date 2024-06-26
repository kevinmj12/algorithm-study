#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<string> mbtis;
int answer;

int getDistance(int a, int b){
    string mbtiA = mbtis[a];
    string mbtiB = mbtis[b];

    int distance = 0;
    for (int i = 0; i < 4; i++){
        if (mbtis[a][i] != mbtis[b][i]){
            distance++;
        }
    }
    return distance;
}

void solve(){
    int size = mbtis.size();
    for (int i = 0; i < size-2; i++){
        for (int j = i+1; j < size-1; j++){
            for (int k = j+1; k < size; k++){
                int a = getDistance(i, j);
                int b = getDistance(j, k);
                int c = getDistance(k, i);
                answer = min(answer, a+b+c);
            }
        }
    }

    cout << answer << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;


        mbtis.clear();
        answer = INT_MAX;

        for (int i = 0; i < n; i++){
            string mbti;
            cin >> mbti;
            
            mbtis.push_back(mbti);
        }
        
        // 비둘기집 원리에 따라 n이 33 이상이면 반드시 거리가 0
        if (n >= 33){
            cout << "0\n";
            continue;
        }
        solve();
    }
}