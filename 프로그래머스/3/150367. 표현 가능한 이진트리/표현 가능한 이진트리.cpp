#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool dfs(int left, int right, bool b, string s){
    if (left > right){
        return true;
    }
    
    int mid = left + (right - left) / 2;
    
    if (b == false && s[mid] == '1'){
        return false;
    }
    else{
        return (dfs(left, mid-1, s[mid] == '1', s) && dfs(mid+1, right, s[mid] == '1', s));
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    vector<string> binaryNums;
    for (long long n : numbers){
        string binaryNum = "";
        while (n){
            binaryNum += (n % 2)+'0';
            n /= 2;
        }
        
        binaryNums.push_back(binaryNum);
    }
    
    for (string s: binaryNums){
        int l = 1;
        int sl = s.length();
        while (sl > l){
            l = (l+1)*2-1;
        }
        while (l > sl){
            s += '0';
            sl++;
        }
        reverse(s.begin(), s.end());
        
        bool flag = dfs(0, sl-1, true, s);
        
        if (flag){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    
    return answer;
}