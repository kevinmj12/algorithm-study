#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct box{
    int beginTown;
    int endTown;
    int amount;
    box(int b, int e, int a): beginTown(b), endTown(e), amount(a) {}
};

bool compareBox(box b1, box b2){
    // (받는 마을번호 - 보내는 마을번호)가 작을수록 우선순위 높음
    if ((b1.endTown-b1.beginTown) != (b2.endTown-b2.beginTown)){
        return (b1.endTown-b1.beginTown) < (b2.endTown-b2.beginTown);
    }
    // (받는 마을번호 - 보내는 마을번호)가 같다면 보내는 마을번호 작은순
    return b1.beginTown < b2.beginTown;
}

int truckBoxes[2001];
void init(int n, int c){
    for (int i = 1; i <= n; i++){
        truckBoxes[i] = c;
    }
}

int main(){
    int n, c, m;
    cin >> n >> c;
    cin >> m;

    vector<box> boxes;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        boxes.push_back(box(a, b, c));
    }

    sort(boxes.begin(), boxes.end(), compareBox);

    init(n, c);

    int answer = 0;
    for (int i = 0; i < m; i++){
        int minBoxes = boxes[i].amount;
        // 각 마을을 지나갈 때 트럭에 들어있는 박스양을 조사
        for (int j = boxes[i].beginTown; j < boxes[i].endTown; j++){
            minBoxes = min(minBoxes, truckBoxes[j]);
        }
        // 조사한 박스양만큼을 반영
        answer += minBoxes;
        for (int j = boxes[i].beginTown; j < boxes[i].endTown; j++){
            truckBoxes[j] -= minBoxes;
        }
    }

    cout << answer;
}