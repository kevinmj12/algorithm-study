#include <iostream>
#include <map>
using namespace std;

int n, m;
int times[100000];
map<int, int> num_map;

bool canPass(unsigned long long time){
    unsigned long long passPeople = 0;
    for (auto it = num_map.begin(); it != num_map.end(); it++){
        passPeople += time / (it->first) * (it->second);
        if (passPeople >= m){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        cin >> times[i];
        num_map[times[i]]++;
    }

    unsigned long long left = 0;
    unsigned long long right = 1000000000000000000;

    while (left <= right){
        unsigned long long mid = left + (right - left) / 2;
        if (!canPass(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << left;
}