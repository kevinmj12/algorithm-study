#include <iostream>
#include <vector>
using namespace std;

vector<int> fibo;
int index = 2;

void init(){
    fibo.push_back(1);
    fibo.push_back(1);
}

void updateFibo(int n){
    int val = fibo[index-1]+fibo[index-2];

    while (val <= n){
        fibo.push_back(val);
        index++;
        val = fibo[index-1]+fibo[index-2];
    }
}

int findFibo(int n){
    int left = 0, right = index-1;
    
    while (left < right){
        int mid = (left+right+1)/2;
        if (fibo[mid] == n){
            return fibo[mid];
        }
        else if (fibo[mid] > n){
            right = mid-1;
        }
        else{
            left = mid;
        }
    }
    return fibo[left];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        if (fibo.back() < n){
            updateFibo(n);
        }

        vector<int> numVec;
        while (n > 0){
            int tmp = findFibo(n);
            n -= tmp;
            numVec.push_back(tmp);
        }

        for (int i = numVec.size()-1; i >= 0; i--){
            cout << numVec[i] << " ";
        }
        cout << "\n";
    }
}