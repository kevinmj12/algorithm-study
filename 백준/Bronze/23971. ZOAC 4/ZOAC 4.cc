#include <iostream>
using namespace std;

int main(){
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int a = (H-1)/(N+1)+1;
    int b = (W-1)/(M+1)+1;
    
    cout << a * b;

    return 0;
}