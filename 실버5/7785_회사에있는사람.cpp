#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, int> members;

    int n;
    cin >> n;

    while (n--){
        string name;
        string command;

        cin >> name >> command;
        if (command == "enter"){
            members.insert({name, 1});
        }
        else{
            members.erase(name);
        }
    }

    auto it = members.end();
    it--;
    for (it; it != members.begin(); it--){
        cout << it->first << "\n";
    }
    cout << it-> first << "\n";
}