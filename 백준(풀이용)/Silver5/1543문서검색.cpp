// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string doc;
//     getline(cin, doc);

//     string word;
//     getline(cin, word);

//     int answer = 0;
//     for (int i = 0; i < doc.length(); i++){
//         int j = 0;
//         int k = i;
//         if (doc[k] == word[j]){
//             while (doc[k+1] == word[j+1] && k+1 < doc.length()){
//                 j++;
//                 k++;
//                 if (j == word.length()-1){
//                     answer++;
//                     i += j;
//                 }
//             }
//         }
//     }

//     cout << answer;
// }

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
        bool isWordIn = true;
        for (int j = 0; j < word.length(); j++){
            if (doc[i+j] != word[j]){
                isWordIn = false;
            }
        }
        if (isWordIn){
            answer++;
            i += word.length()-1;
        }
    }

    cout << answer;
}