#include <iostream>
#include <queue>

using namespace std;



int main(){
    int n, w, l, shortestTime = 0;
    cin >> n >> w >> l;
    queue<int> truck;
    queue<int> bridge;
    for (int i = 0; i < n; i++){
        int wTruck;
        cin >> wTruck;
        truck.push(wTruck);
    }
    for (int i = 0; i < w; i++){
        bridge.push(0);
    }
    while (!truck.empty()){
            l += bridge.front();
            bridge.pop();
            shortestTime++;

        if (truck.front() <= l){
            bridge.push(truck.front());
            l -= truck.front();
            truck.pop();
        }
        else{
            bridge.push(0);
        }
    }
    cout << shortestTime + w;

}