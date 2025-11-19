#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // (100+1+ | 01)+
    int T;
    cin >> T;

    while (T--){
        string str;
        cin >> str;

        int N = str.length();
        bool isPattern = true;
        int idx = 0;
        int zeroCnt = 0;
        int oneCnt = 0;

        while (idx < N){
            // 100+1+
            if (str[idx] == '1'){
                zeroCnt = 0;
                oneCnt = 0;
                // 0을 탐색
                while (idx+1 < N && str[idx+1] == '0'){
                    zeroCnt++;
                    idx++;
                }
                // 0이 1개 이하인 경우
                if (zeroCnt <= 1){
                    isPattern = false;
                    break;
                }
                // 1을 탐색
                while (idx+1 < N && str[idx+1] == '1'){
                    oneCnt++;
                    idx++;
                }
                if (oneCnt < 1){
                    isPattern = false;
                    break;
                }
                
                // 그대로 끝난 경우
                if (idx == N-1){
                    break;
                }
                // 다음이 0으로 끝나는 경우
                if (idx == N-2){
                    isPattern = false;
                    break;
                }
                // 다음이 01인 경우
                else if (str[idx+2] == '1'){
                    idx++;
                }
                // 다음이 00인 경우
                else{
                    // 1이 1개만 있었다면 100+1+가 다시 올 수 없음
                    if (oneCnt == 1){
                        isPattern = false;
                        break;
                    }
                }
            }
            // 01
            if (str[idx] == '0'){
                if (idx+1 < N && str[idx+1] == '1'){
                    idx+=2;
                }
                else{
                    isPattern = false;
                    break;
                }
            }
        }

        if (isPattern){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}