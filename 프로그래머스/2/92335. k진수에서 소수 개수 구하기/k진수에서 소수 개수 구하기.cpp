#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string decToK(int n, int k){
    string rtn = "";
    while (n > k){
        rtn += (n % k) + '0';
        n /= k;
    }
    rtn += n + '0';
    reverse(rtn.begin(), rtn.end());
    
    return rtn;
}

bool isPrime(long long p){
    if (p == 1){
        return false;
    }
    for (long long i = 2; i*i <= p; i++){
        if ((p % i) == 0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string nk = decToK(n, k);
    
    // int maxP = 0;
    string strP = "";
    vector<long long> pVec;
    
    for (int i = 0; i < nk.length(); i++){
        if (nk[i] != '0'){
            strP += nk[i];
        }
        else{
            if (strP.length()){
                long long p = stoll(strP);
                pVec.push_back(p);
                // maxP = max(maxP, p);
            }
            strP = "";
        }
    }
    
    if (strP.length()){
        long long p = stoll(strP);
        pVec.push_back(p);
        // maxP = max(maxP, p);
    }
    
    // maxP까지 소수 판별
//     vector<bool> isPrime(maxP+1, true);
//     isPrime[1] = false;
    
//     for (int i = 2; i*i <= maxP; i++){
//         if (isPrime[i] == true){
//             int ii = i + i;
//             while (ii <= maxP){
//                 isPrime[ii] = false;
//                 ii += i;
//             }
//         }
//         else{
//             continue;
//         }
//     }
    
//     for (int p: pVec){
//         if (isPrime[p]){
//             answer++;
//         }
//     }
    
    // cout << nk << "\n";
    for (long long p: pVec){
        if (isPrime(p)){
            answer++;
        }
    }
    
    return answer;
}