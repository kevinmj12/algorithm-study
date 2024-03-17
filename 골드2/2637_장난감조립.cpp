#include <iostream>
#include <vector>
using namespace std;

#define MAX 101
int n, m;
// {필요 부품, 부품 개수}로 저장
vector<pair<int, int>> toys[MAX];
// 다른 부품의 재료가 되는 횟수 저장
int cnt[MAX];
int answer[MAX];

void solve(){
    while (true){
        // cnt가 0인 장난감 부품을 찾음
        int toy;
        for (int i = 1; i <= n; i++){
            if (cnt[i] == 0){
                toy = i;
                cnt[i]--;
                break;
            }
            // 더 이상 장난감을 필요로 하지 않는 경우 종료
            if (i == n){
                return;
            }
        }

        // target이 기본 부품인 경우
        if (!toys[toy].size()){
            continue;
        }
        // target이 중간 부품인 경우
        else{
            for (int i = 0; i < toys[toy].size(); i++){
                int target = toys[toy][i].first;
                int amount = toys[toy][i].second;
                
                answer[target] += answer[toy]*amount;
                cnt[target]--;
            }
            answer[toy] = 0;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        toys[a].push_back({b,c});

        // 부품이 다른 부품의 재료가 되는 경우 count[b] 증가
        cnt[b]++;
    }

    answer[n]++;
    solve();

    for (int i = 1; i <= n; i++){
        if (answer[i]){
            cout << i << " " << answer[i] << "\n";
        }
    }
}