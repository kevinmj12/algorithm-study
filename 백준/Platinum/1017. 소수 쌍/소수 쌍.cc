#include <iostream>
#include <vector>
#include <set>
using namespace std;

int nums[51];
bool isPrime[2001];

vector<int> isAble[51];
int assign[51];
bool visited[51];
set<int> answerSet;

void init(){
    for (int i = 2; i <= 2000; i++){
        isPrime[i] = true;
    }


    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= 2000; i++){
        if (isPrime[i]){
            int j = i * 2;
            while (j <= 2000){
                isPrime[j] = false;
                j += i;
            }
        }
    }
}

void findAble(int n){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (isPrime[nums[i]+nums[j]]){
                isAble[i].push_back(j);
                isAble[j].push_back(i);
            }
        }
    }
}

void resetVisited(int n){
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

void resetAssign(int n){
    for (int i = 1; i <= n; i++){
        assign[i] = 0;
    }
}

bool dfs(int idx, int a, int b){
    if (assign[idx]){
        return true;
    }
    for (int i = 0; i < isAble[idx].size(); i++){
        int target = isAble[idx][i];

        if (visited[target] || target == a || target == b){
            continue;
        }

        visited[target] = true;
        int origin = assign[target];

        if (origin == 0){
            assign[idx] = target;
            assign[target] = idx;
            return true;
        }
        else {
            assign[target] = 0;
            assign[origin] = 0;
            if (dfs(origin, a, b)){
                assign[idx] = target;
                assign[target] = idx;
                return true;
            }
            else{
                assign[target] = origin;
                assign[origin] = target;
            }
        }
    }
    return false;
}

void solve(int n){
    for (int i = 0; i < isAble[1].size(); i++){
        resetAssign(n);
        int target = isAble[1][i];
        assign[1] = target;
        assign[target] = 1;

        bool flag = true;
        for (int j = 2; j <= n; j++){
            resetVisited(n);
            if (!dfs(j, 1, target)){
                flag = false;
                break;
            }
        }

        if (flag){
            answerSet.insert(nums[target]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    init();

    findAble(N);

    solve(N);

    if (answerSet.empty()){
        cout << -1;
    }
    else{
        for (auto i: answerSet){
            cout << i << " ";
        }
    }
}