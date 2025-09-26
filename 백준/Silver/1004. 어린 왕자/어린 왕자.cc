#include <iostream>
#include <cmath>
using namespace std;

bool isInside(int x, int y, int cx, int cy, int r){
    int distance = pow(x-cx, 2) + pow(y-cy, 2);
    if (distance < r*r){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int answer = 0;
        for (int i = 0; i < n; i++){
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool startInside = isInside(x1, y1, cx, cy, r);
            bool endInside = isInside(x2, y2, cx, cy, r);

            if (startInside ^ endInside){
                answer++;
            }
        }

        cout << answer << "\n";
    }
}