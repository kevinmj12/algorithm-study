#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000
int primeNum[MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> primeNumber;

    for (int i = 2; i <= MAX; i++){
        primeNum[i] = 1;
    }

    for (int i = 2; i <= MAX; i++){
        if (primeNum[i]){
            primeNumber.push_back(i);
            int tmp = i * 2;
            while (tmp <= MAX){
                primeNum[tmp] = 0;
                tmp += i;
            }
        }
    }

    while (true){
        int n;
        cin >> n;
        
        if (n == 0){
            break;
        }
        for (int i = 0; i < primeNumber.size(); i++){
            int trg = primeNumber[i];
            if (primeNum[n - trg] && n - trg != 1){
                cout << n << " = " << trg << " + " << n-trg << "\n";
                break;
            }
        }
    }
}