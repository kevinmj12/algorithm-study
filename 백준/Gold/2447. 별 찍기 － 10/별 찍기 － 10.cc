#include <iostream>
#include <vector>
using namespace std;

bool answer[2188][2188];

void solve(int n, int y, int x){
    if (n == 3){
        answer[y][x] = true;
        answer[y][x+1] = true;
        answer[y][x+2] = true;
        answer[y+1][x] = true;
        // 가운데 빈 칸
        answer[y+1][x+2] = true;
        answer[y+2][x] = true;
        answer[y+2][x+1] = true;
        answer[y+2][x+2] = true;
    }
    else{
        solve(n/3, y, x);
        solve(n/3, y, x + (n/3));
        solve(n/3, y, x + (2*n/3));
        solve(n/3, y + (n/3), x);
        // 가운데 빈 칸
        solve(n/3, y + (n/3), x + (2*n/3));
        solve(n/3, y + (2*n/3), x);
        solve(n/3, y + (2*n/3), x + (n/3));
        solve(n/3, y + (2*n/3), x + (2*n/3));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    solve(n, 0, 0);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (answer[i][j]){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}