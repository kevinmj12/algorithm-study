#include <iostream>
#include <string>
using namespace std;

int main(){
    string doc;
    getline(cin, doc);

    string word;
    getline(cin, word);

    int answer = 0;
    for (int i = 0; i < doc.length(); i++){
        int j = 0;
        if (doc[i] == word[j]){
            if (j == word.length()-1){
                answer++;
            }
            else{
                while (doc[i+1] == word[j+1]){
                    i++;
                    j++;  
                    if (j == word.length()-1){
                        answer++;
                        break;
                    }
                }
            }
            
        }
    }

    cout << answer;
}