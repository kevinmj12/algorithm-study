#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int diffMN = M-N;
        int diffXY = x-y;


        int cnt = x;
        int b = x % N;
        if (b == 0){
            b = N;
        }
        bool isPrinted = false;
        while (cnt <= M*N){
            if (b == y){
                cout << cnt << "\n";
                isPrinted = true;
                break;
            }
            b = (b + M) % N;
            if (b == 0){
                b = N;
            }
            cnt += M;
        }
        if (!isPrinted){
            cout << "-1\n";
        }
        
    }
}