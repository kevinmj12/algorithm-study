#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, P;
    cin >> N >> P;

    stack<int> s[6];
    long long answer = 0;

    while (N--){
        int string, fret;
        cin >> string >> fret;

        string--;

        if (s[string].empty()){
            s[string].push(fret);
            answer++;
        }
        else{
            if (s[string].top() < fret){
                s[string].push(fret);
                answer++;
            }
            else if (s[string].top() > fret){
                while (!s[string].empty() && s[string].top() > fret){
                    answer++;
                    s[string].pop();
                }
                if (s[string].empty() || s[string].top() != fret){
                    s[string].push(fret);
                    answer++;
                }
            }
        }
    }

    cout << answer;
}
