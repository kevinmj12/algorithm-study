#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;

        string answer = "";
        if (N % 2){
            answer += "1";
            for (int i = 0; i < N-1; i++){
                answer += "0";
            }
        }
        else{
            answer += "25";
            for (int i = 0; i < N-2; i++){
                answer += "0";
            }
        }
        cout << answer << "\n";
    }
}