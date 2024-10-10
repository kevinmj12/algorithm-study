#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

string to_binary(long long l){
    string rtn = "";
    while (l > 0){
        rtn += (l % 2) + '0';
        l >>= 1;
    }
    reverse(rtn.begin(), rtn.end());
    return rtn;
}

bool canExpress(string str){
    int depth = 1;
    while (true){
        int tmp = pow(2, depth);
        if (tmp > str.length()){
            if (str[str.length()/2] == '1'){
                return true;    
            }
            else{
                return false;
            }
        }
        
        for (int i = tmp/2-1; i < str.length(); i += tmp*2){
            int left = i;
            int right = i+tmp;

            if (str[left] == '1' || str[right] == '1'){
                if (str[(left + right)/2] == '0'){
                    return false;
                }
            }
        }
        depth++;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size(); i++){
        bool flag = false;
        string str = to_binary(numbers[i]);        
        
        // 앞뒤로 0을 붙여 문자열의 길이가 (2^n)-1이 되도록 설정
        int tmp = 1;
        while (true){
            if (tmp > str.length()){
                break;
            }
            tmp *= 2;
        }
        
        string newStr = string(tmp-1-str.length(), '0') + str;

        // 이진 트리로 만들 수 있는지를 체크
        if (canExpress(newStr)){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
        
    }
    return answer;
}