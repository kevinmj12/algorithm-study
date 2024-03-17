#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, k;
pair<int, int> root[100001];
bool error[100001];

void resetRoot(){
    for (int i = 1; i <= n; i++){
        root[i] = {i,0};
    }
}

// {관계의 대상이 되는 사람, 관계} 를 저장
pair<int, int> Find(int a, int r){
    if (a == root[a].first){
        return {a, r};
    }
    else{
        return Find(root[a].first, (r+root[a].second)%2);
    }
}

void Union(int a, int b, int r){
    pair<int, int> parentA = Find(a, 0);
    pair<int, int> parentB = Find(b, 0);
    // a와 b의 부모가 같은 경우
    if (parentA.first == parentB.first){
        // 기존의 관계와 주어진 관계가 다른 경우 Error
        if ((parentA.second+parentB.second)%2 != r){
            error[parentA.first] = true;
        } 
    }
    // a와 b의 부모가 다른 경우
    else{
        if (parentA.first < parentB.first){
            root[parentB.first] = {parentA.first, (r + parentA.second + parentB.second)%2};
            // parentB.first가 Error인 경우 parentA.first도 에러
            if (error[parentB.first]){
                error[parentA.first] = true;
            }
        }
        else{
            root[parentA.first] = {parentB.first, (r + parentA.second + parentB.second)%2};
            // parentA.first가 Error인 경우 parentB.first도 에러
            if (error[parentA.first]){
                error[parentB.first] = true;
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    resetRoot();

    for (int i = 0; i < m; i++){
        int t, a, b;
        cin >> t >> a >> b;
        
        Union(a, b, t);
    }


    while (k--){
        int a, b;
        cin >> a >> b;

        pair<int, int> parentA = Find(a, 0);
        pair<int, int> parentB = Find(b, 0);

        // 부모가 다른 경우 Unknown
        if (parentA.first != parentB.first){
            cout << "Unknown\n";
        }
        // 부모가 같은 경우
        else {
            // 부모가 에러인 경우
            if (error[parentA.first]){
                cout << "Error\n";
            }
            // 이외의 경우 관계를 계산
            else{
                int relation = (parentA.second + parentB.second)%2;
                if (relation){
                    cout << "Enemy\n";
                }
                else{
                    cout << "Friend\n";
                }
            }
        }

    }
}