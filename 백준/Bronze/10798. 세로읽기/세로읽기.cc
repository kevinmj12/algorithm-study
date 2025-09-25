#include <iostream>
#include <algorithm>
using namespace std;

string strs[5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    size_t maxLength = 0;
    for (int i = 0; i < 5; i++){
        cin >> strs[i];
        maxLength = max(maxLength, strs[i].length());
    }

    int index = 0;
    string answer = "";
    while (index < maxLength){
        for (int i = 0; i < 5; i++){
            if (strs[i].length() > index){
                answer += strs[i][index];
            }
        }
        index++;
    }
    cout << answer;
}