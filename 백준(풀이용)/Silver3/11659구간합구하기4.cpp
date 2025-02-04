#include <iostream>
using namespace std;
#define MAX 100001
int sum[MAX];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }

    while (m--){
        int start, end;
        cin >> start >> end;
        cout << sum[end]-sum[start-1] << "\n";
    }
}