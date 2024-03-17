#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;

    stack<char> ppap;

    for (int i = 0; i < input.length(); i++){
        if (input[i] == 'P' && ppap.size() >= 3){
            char a = ppap.top();
            ppap.pop();

            char b = ppap.top();
            ppap.pop();

            char c = ppap.top();
            ppap.pop();

            if (a == 'A' && b == 'P' && c == 'P'){
                ppap.push('P');
            }
            else{
                ppap.push(c);
                ppap.push(b);
                ppap.push(a);
                ppap.push(input[i]);
            }
        }
        else{
            ppap.push(input[i]);
        }
    }
    if (ppap.size() == 1 && ppap.top() == 'P'){
        cout << "PPAP";
    }
    else{
        cout << "NP";
    }
}
