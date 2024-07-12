#include <iostream>
using namespace std;
int n, m;
int nums[1025][1025];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    
    for (int i  = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int a;
            cin >> a;
            nums[i][j] = a + nums[i][j-1];
        }
    }

    while (m--){
        int answer = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; x++){
            answer += nums[x][y2] - nums[x][y1-1];
        }

        cout << answer << "\n";
    }


}