#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

char letters[15];
set<char> vowels;
int l, c;

void backtracking(vector<char> vec, int idx){
    if (vec.size() == l){
        int numVowel = 0;
        for (int i = 0; i < l; i++){
            if (vowels.find(vec[i]) != vowels.end()){
                numVowel++;
            }
        }
        if (numVowel >= 1 && l-numVowel >= 2){
            for (int i = 0; i < l; i++){
                cout << vec[i];
            }   
            cout << "\n";
        }
        return;
    }
    for (idx; idx < c; idx++){
        vec.push_back(letters[idx]);
        backtracking(vec, idx+1);
        vec.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> l >> c;

    for (int i = 0; i < c; i++){
        cin >> letters[i];
    }

    sort(letters, letters+c);

    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    backtracking({}, 0);
}