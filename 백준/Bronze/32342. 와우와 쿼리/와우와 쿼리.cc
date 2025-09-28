#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++){
        string input;
        cin >> input;

        int answer = 0;
        bool isW = false;
        bool isO = false;
        for (auto s : input){
            if (s == 'W'){
                if (isO){
                    answer++;
                }
                isW = true;
                isO = false;
            }
            else{
                if (isW){
                    isW = false;
                    isO = true;
                }
                else{
                    isW = false;
                    isO = false;
                }
            }
        }

        cout << answer << "\n";
    }
}