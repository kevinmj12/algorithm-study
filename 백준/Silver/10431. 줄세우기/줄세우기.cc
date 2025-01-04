#include <iostream>
#include <vector>
using namespace std;

int heights[20];

int main(){
    int p;
    cin >> p;

    while (p--){
        int t;
        cin >> t;

        int answer = 0;

        for (int i = 0; i < 20; i++){
            cin >> heights[i];

            for (int j = 0; j < i; j++){
                if (heights[j] > heights[i]){
                    int k = i;
                    while (k > j){
                        swap(heights[k], heights[k-1]);
                        k--;
                        answer++;
                    }
                    break;
                }
            }
        }

        cout << t << " " << answer << "\n";
    }
}