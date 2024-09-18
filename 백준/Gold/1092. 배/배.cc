#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cranes[50];
vector<int> boxes;
int craneBox[50];

bool compare(int a, int b){
    return a > b;
}

int main(){
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> cranes[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        int box;
        cin >> box;
        boxes.push_back(box);
    }

    sort(cranes, cranes+n, compare);
    sort(boxes.begin(), boxes.end(), compare);

    // 박스를 옮길 수 없다면 종료
    if (boxes[0] > cranes[0]){
        cout << -1;
        return 0;
    }

    int answer = 0;
    while (!boxes.empty()){
        answer++;

        int craneIdx = 0;
        int boxIdx = 0;
        while (craneIdx < n && boxIdx < boxes.size()){
            if (cranes[craneIdx] >= boxes[boxIdx]){
                boxes.erase(boxes.begin()+boxIdx);
                craneIdx++;
            }
            else{
                boxIdx++;
            }
        }
    }

    cout << answer;
}