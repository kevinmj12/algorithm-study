#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool people[51];
vector<int> parties[51];

int root[51];

void resetRoot(){
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }
}

int Find(int x){
    if (x == root[x]){
        return x;
    }
    return root[x] = Find(root[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    // x가 진실을 아는 사람일 경우
    if (people[x]){
        root[y] = x;
    }
    // y가 진실을 아는 사람일 경우
    else if (people[y]){
        root[x] = y;
    }
    // 이외의 경우 그냥 Union
    else if (x < y){
        root[y] = x;
    }
    else{
        root[x] = y;
    }
}

int main(){
    cin >> n >> m;
    
    int knowPeople;
    cin >> knowPeople;
    for (int i = 0; i < knowPeople; i++){
        int person;
        cin >> person;

        people[person] = true;
    }

    resetRoot();
    for (int i = 1; i <= m; i++){
        int partyPeople;
        cin >> partyPeople;

        int p;
        cin >> p;
        parties[i].push_back(p);
        for (int j = 1; j < partyPeople; j++){
            int p;
            cin >> p;
            parties[i].push_back(p);
            Union(parties[i][j-1], parties[i][j]);
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= m; i++){
        bool canLie = true;
        for (int j = 0; j < parties[i].size(); j++){
            if (people[Find(parties[i][j])]){
                canLie = false;
                break;
            }
        }
        if (canLie){
            answer++;
        }
    }

    cout << answer;
}