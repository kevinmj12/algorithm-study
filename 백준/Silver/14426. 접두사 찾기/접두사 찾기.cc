#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> strs;

bool BinarySearch(string s){
    int left = 0, right = strs.size()-1;
    int mid;

    int index = 0;
    while (left <= right && index < s.length()){
        mid = (left + right) / 2;

        if (s[index] == strs[mid][index]){
            index++;
        }
        else if (s[index] > strs[mid][index]){
            left = mid + 1;
            index = 0;
        }
        else{
            right = mid - 1;
            index = 0;
        }
    }
    if (index >= s.length()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string input;
        cin >> input;
        strs.push_back(input);
    }

    sort(strs.begin(), strs.end());
    
    int answer = 0;

    for (int i = 0; i < m; i++){
        string s;
        cin >> s;

        if (BinarySearch(s)){
            answer++;
        }
    }

    cout << answer;
}