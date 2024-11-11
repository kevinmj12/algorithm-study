#include <iostream>
#include <map>
#include <queue>
using namespace std;

string nums = "";
map<string, bool> numMap;
string answer = "";

int solve(int n, int k){
    queue<string> que;
    que.push(nums);
    numMap[nums] = true;
    int cnt = 0;

    while (!que.empty()){
        int size = que.size();
        for (int i = 0; i < size; i++){
            string str = que.front();
            que.pop();

            if (str == answer){
                return cnt;
            }

            for (int j = 0; j <= n-k; j++){
                string tmp = "";
                for (int l = 0; l < j; l++){
                    tmp += str[l];
                }
                for (int l = j+k-1; l >= j; l--){
                    tmp += str[l];
                }
                for (int l = j+k; l < n; l++){
                    tmp += str[l];
                }
                if (!numMap[tmp]){
                    numMap[tmp] = true;
                    que.push(tmp);
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        char num;
        cin >> num;
        nums += num;
        answer += (i+1)+'0';
    }

    cout << solve(n, k);
}