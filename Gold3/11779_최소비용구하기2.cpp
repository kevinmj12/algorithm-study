#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_BUS 1001
#define MAX_COST 1000000000
vector<pair<int, int>> info[MAX_BUS];
int root[MAX_BUS];
int answer[MAX_BUS];

int n, m;
int start, finish;

void reset(){
    for (int i = 1; i <= n; i++){
        answer[i] = MAX_COST;
    }
}

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()){
        int cost = pq.top().first;
        int city = pq.top().second;

        pq.pop();

        if (city == finish){
            return;
        }
        if (cost > answer[city]){
            continue;
        }

        for (int i = 0; i < info[city].size(); i++){
            int nextCity = info[city][i].first;
            int nextCost = info[city][i].second;
            if (answer[nextCity] > cost+nextCost){
                answer[nextCity] = cost+nextCost;
                pq.emplace(cost+nextCost, nextCity);
                root[nextCity] = city;
            }
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
        
        info[a].push_back({b, c});
    }

    cin >> start >> finish;

    reset();
    answer[start] = 0;
    solve();

    vector<int> cities;
    int previous = finish;
    while (previous != start){
        cities.push_back(previous);
        previous = root[previous];
    }

    cout << answer[finish] << "\n";
    cout << cities.size()+1 << "\n";
    cout << start << " ";
    for (int i = cities.size()-1; i >= 0; i--){
        cout << cities[i] << " ";
    }
}