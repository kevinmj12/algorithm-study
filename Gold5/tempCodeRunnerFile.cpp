#include <iostream>
#include <stack>
using namespace std;

int tower[500001];
int answer[500001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> tower[i];
    }

    int cursor = n;
    stack<int> s;
    while (cursor > 0){
        s.push(cursor);
        int tmp = cursor-1;
        while (tmp > 0 && tower[tmp] <= tower[s.top()]){
            s.push(tmp);
            tmp--;
        }
        if (tmp == 0){
            for (int i = tmp+1; i <= cursor; i++){
                answer[i] = 0;
            }    
        }
        else{
            while (!s.empty() && tower[tmp] > tower[s.top()]){
                answer[s.top()] = tmp;
                s.pop();
            }
        }
        cursor = tmp;
    }

    for (int i =1; i <= n; i++){
        cout << answer[i] << " ";
    }
}