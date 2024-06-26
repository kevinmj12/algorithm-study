#include <iostream>
#include <string>
using namespace std;


int main(){
    int N;
    cin >> N;
    int i = 0;

    while (N > 0){
        i++;
        if (to_string(i).find("666") != string::npos){
            // find("text")에서 text가 없으면 npos를 반환함.
            N -= 1;
        }
    }

    cout << i;
}