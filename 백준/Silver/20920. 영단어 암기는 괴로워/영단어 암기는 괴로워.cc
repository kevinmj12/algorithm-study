#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Word{
    string name;
    int count;
    Word(string n, int c){
        name = n;
        count = c;
    }
};

bool compare(Word a, Word b){
    if (a.count > b.count){
        return true;
    }
    else if (a.count < b.count){
        return false;
    }

    if (a.name.length() > b.name.length()){
        return true;
    }
    else if (a.name.length() < b.name.length()){
        return false;
    }

    if (a.name < b.name){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    map<string, int> wordMap;
    vector<Word> wordVec;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        string word;
        cin >> word;

        if (word.length() < M){
            continue;
        }
        if (wordMap.find(word) != wordMap.end()){
            wordMap[word]++;
        }
        else{
            wordMap.insert({word, 1});
        }
    }

    for (auto it = wordMap.begin(); it != wordMap.end(); it++){
        wordVec.push_back(Word(it->first, it->second));
    }

    sort(wordVec.begin(), wordVec.end(), compare);

    for (Word w: wordVec){
        cout << w.name << "\n";
    }
}