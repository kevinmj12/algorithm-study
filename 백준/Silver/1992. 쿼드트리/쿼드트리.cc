#include <iostream>
#include <string>
using namespace std;

string video[64][64];
string solve(int y, int x, int size){
    if (size >= 2){
        string a = solve(y, x, size/2);
        string b = solve(y, x+size/2, size/2);
        string c = solve(y+size/2, x, size/2);
        string d = solve(y+size/2, x+size/2, size/2);
        if (a.size() == 1 && a == b && b == c && c == d){
            return a;
        }
        else{
            return '('+a+b+c+d+')';
        }
    }
    else{
        return (video[y][x]);
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string input;
        cin >> input;
        for (int j = 0; j < n; j++){
            video[i][j] = input[j];
        }
    }

    string answer =  solve(0, 0, n);
    cout << answer;

}