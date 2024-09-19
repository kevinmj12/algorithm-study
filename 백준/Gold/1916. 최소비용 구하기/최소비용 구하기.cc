#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    
    multimap<int, int> bus[n+1]; // map<cost, city>
    for (int i = 1; i < m+1; i++){
        int startCity, endCity, cost;
        cin >> startCity >> endCity >> cost;
        bus[startCity].insert({cost, endCity});
    }

    int sCity, eCity;
    cin >> sCity >> eCity;
    int busCost[n+1];
    bool cities[n+1];
    for (int i = 0; i < n+1; i++){
        busCost[i] = INT_MAX;
        cities[i] = 0;
    }
    for (auto it = bus[sCity].begin(); it != bus[sCity].end(); it++){
        busCost[it->second] = it->first;
    }

    while (cities[eCity] == 0){
        int u = bus[sCity].begin()->second, ucost = bus[sCity].begin()->first;
        bus[sCity].erase(bus[sCity].begin());
        cities[u] = 1;
        busCost[u] = ucost;
        for (auto it = bus[u].begin(); it != bus[u].end(); it++){
            if (cities[it->second] == 0 && ucost + it->first < busCost[it->second]){
                busCost[it->second] = ucost + it->first;
                bus[sCity].insert({ucost+it->first, it->second});
            }
        }
    }
    cout << busCost[eCity];
    
}