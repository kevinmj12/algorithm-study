#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int answer = 0;
int energies[10];
bool addEnergy[10];

int findMaxEnergy(int idx){
    int left, right;
    for (int i = idx-1; i >= 0; i--){
        if (addEnergy[i]){
            left = i;
            break;
        }
    }
    for (int i = idx+1; i < n; i++){
        if (addEnergy[i]){
            right = i;
            break;
        }
    }

    return energies[left] * energies[right]; 
}

void solve(int total){
    vector<int> vec;
    bool allTrue = true;
    for (int i = 1; i < n-1; i++){
        if (!addEnergy[i]){            
            allTrue = false;
            addEnergy[i] = true;
            solve(total + findMaxEnergy(i));
            addEnergy[i] = false;
        }
    }
    if (allTrue){
        answer = max(answer, total);
        return;
    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> energies[i];
    }

    addEnergy[0] = true;
    addEnergy[n-1] = true;

    solve(0);

    cout << answer;
}