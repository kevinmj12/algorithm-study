#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int len = s.length();
    
    for (int div = 1; div <= len/2; div++){
        int zippedLen = 0;
        
        for (int i = 0; i < len; i += div){
            if (i + (2 * div) - 1 >= len){
                zippedLen += (len - i);
                break;
            }
            
            string a = s.substr(i, div);
            int nextI = i + div;
            while (nextI + div - 1 < len){
                if (s.substr(nextI, div) == a){
                    nextI += div;    
                }
                else{
                    break;
                }
            }
            
            if (nextI == i + div){
                zippedLen += div;
            }
            else{
                string tmp = to_string((nextI - i) / div);
                zippedLen += tmp.length() + div;
                i = nextI - div;
            }
        }
        
        answer = min(answer, zippedLen);
    }
    return answer;
}