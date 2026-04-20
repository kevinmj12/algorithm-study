#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    int maxSize = 1;
    sort(mats.begin(), mats.end());
    
    for (int r = 0; r < park.size(); r++){
        for (int c = 0; c < park[0].size(); c++){
            if (park[r][c] != "-1"){
                continue;
            }
            int m = maxSize+1;
        
            while (true){
                if (r+m-1 >= park.size() ||
                   c+m-1 >= park[0].size()){
                    break;
                }
                
                bool flag = true;
                for (int y = r; y <= r+m-1; y++){
                    for (int x = c; x <= c+m-1; x++){
                        if (park[y][x] != "-1"){
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false){
                        break;
                    }
                }
                if (flag){
                    maxSize = m;
                    m++;
                }
                else{
                    break;
                }
            }
        }
    }
    
    for (int m: mats){
        if (maxSize >= m){
            answer = m;
        }
    }
    return answer;
}