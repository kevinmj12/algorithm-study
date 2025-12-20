#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Word {
    string name;
    int count;
    Word(string n, int c) : name(n), count(c) {}
};

bool compare(const Word& a, const Word& b) {
    if (a.count != b.count) return a.count > b.count;
    if (a.name.length() != b.name.length()) return a.name.length() > b.name.length();
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> wordMap;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.length() < M) continue;
        wordMap[word]++;
    }

    vector<Word> wordVec;
    for (const auto& item : wordMap) {
        wordVec.emplace_back(item.first, item.second);
    }

    sort(wordVec.begin(), wordVec.end(), compare);

    for (const auto& w : wordVec) {
        cout << w.name << "\n";
    }

    return 0;
}