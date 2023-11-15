#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    queue<string> userList[201];
    for (int i = 0; i < n; i++){
        int age; string name;
        cin >> age >> name;
        userList[age].push(name);        
    }
    for (int i = 0; i < 201; i++){
        if (userList[i].empty()){
            continue;
        }
        else{
            while (!userList[i].empty()){
                cout << i << " " << userList[i].front() << "\n";
                userList[i].pop();
            }
        }
    }
}