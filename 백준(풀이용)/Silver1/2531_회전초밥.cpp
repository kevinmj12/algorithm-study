#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, d, k, c;
vector<int> sushi;
int numSushiOnTable[3001];
int selectedSushi[3001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        sushi.push_back(s);
        numSushiOnTable[s]++;
    }
    // 인덱스 문제 해결을 위해 앞에서부터 k만큼 초밥을 뒤에 추가
    for (int i = 0; i < k; i++){
        sushi.push_back(sushi[i]);
    }

    // 기본값 설정
    int left = 0, right = k-1;
    int maxKinds = 0;
    int kind = 0;
    for (int i = left; i <= right; i++){
        int target = sushi[i];
        if (!selectedSushi[target]){
            kind++;
        }
        selectedSushi[target]++;
        numSushiOnTable[target]--;
    }
    // 쿠폰 체크
    // 먹은 스시 중에 쿠폰에 해당되는 스시가 없고
    if (!selectedSushi[c]){
        // 벨트 위에도 쿠폰에 해당되는 스시가 없다면
        if (!numSushiOnTable[c]){
            maxKinds = max(maxKinds, kind+1);
        }
        // // 왼쪽 또는 오른쪽에 쿠폰에 해당되는 스시가 있다면
        // else if (sushi[sushi.size()-k-1] == c || sushi[right+1] == c){
        //     maxKinds = max(maxKinds, kind+1);
        // }
        maxKinds = max(maxKinds, kind+1);
    }
    else{
        maxKinds = max(maxKinds, kind);
    }

    // n까지 left와 right를 한 칸씩 옮기며 판단
    while (right+2 < n+k){
        // 왼쪽 제거
        int removeTarget = sushi[left];
        if (selectedSushi[removeTarget] == 1){
            kind--;
        }
        selectedSushi[removeTarget]--;
        numSushiOnTable[removeTarget]++;
        left++;
        // 오른쪽 추가
        right++;
        int insertTarget = sushi[right];
        if (!selectedSushi[insertTarget]){
            kind++;
        }
        selectedSushi[insertTarget]++;
        numSushiOnTable[insertTarget]--;

        // 쿠폰 체크
        // 먹은 스시 중에 쿠폰에 해당되는 스시가 없고
        if (!selectedSushi[c]){
            // 벨트 위에도 쿠폰에 해당되는 스시가 없다면
            if (!numSushiOnTable[c]){
                maxKinds = max(maxKinds, kind+1);
            }
            // // 왼쪽 또는 오른쪽에 쿠폰에 해당되는 스시가 있다면
            // else if (sushi[left-1] == c || sushi[right+1] == c){
            //     maxKinds = max(maxKinds, kind+1);
            // }
            // maxKinds = max(maxKinds, kind+1);
        }
        else{
            maxKinds = max(maxKinds, kind);
        }
    }

    cout << maxKinds;
}