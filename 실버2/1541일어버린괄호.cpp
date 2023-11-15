#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;

    int answer = 0;
    string tmpInt = "";
    bool isMinus = false;
    int i = 0;
    while (i < str.length()+1){
        if (str[i] == '+' || str[i] == '-' || i == str.length()){
            // isMinus가 true이면 빼기
            if (isMinus){
                answer -= stoi(tmpInt);
                tmpInt = "";
            }
            // isMinus가 false이면 더하기
            else{
                answer += stoi(tmpInt);
                tmpInt = "";
            }
        }
        else{
            tmpInt += str[i];
        }

        // isMinus를 true로 설정(이후로 오는 모든 수를 빼기 위해)
        if (str[i] == '-'){
            isMinus = true;
        }
        
        i++;
    }

    printf("%d", answer);
}