#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxL = 0;

void backtracking(int d, int s, int l, int distLimit, int splitLimit){
    if (distLimit == d || s * 2 > splitLimit){
        maxL = max(maxL, l);
        return;
    }
    
    int ableD = min(distLimit - d, l);
    
    backtracking(d+ableD, s*2, l + ableD, distLimit, splitLimit); 
    if (s * 3 <= splitLimit){
        backtracking(d+ableD, s*3, l + 2 * ableD, distLimit, splitLimit);
    }
    
}

int solution(int dist_limit, int split_limit) {
    int answer = 0;
    
    backtracking(0, 1, 1, dist_limit, split_limit);
    
    answer = maxL;
    
    return answer;
}