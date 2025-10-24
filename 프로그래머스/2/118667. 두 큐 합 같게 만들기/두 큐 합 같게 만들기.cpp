#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<int> q1, vector<int> q2, long sum1, long sum2){
    int i1 = 0, i2 = 0;
    int cnt = 0;
    int size = q1.size() + q2.size()+1;
    
    while (sum1 != sum2){
        if (cnt > size){
            return -1;
        }
        if (sum1 > sum2){
            sum1 -= q1[i1];
            sum2 += q1[i1];
            q2.push_back(q1[i1]);
            i1++;
        }
        else{
            sum1 += q2[i2];
            sum2 -= q2[i2];
            q1.push_back(q2[i2]);
            i2++;
        }
        cnt++;
    }
    return cnt;
}

int solution(vector<int> queue1, vector<int> queue2) {
    long s1 = 0, s2 = 0;
    for (int n: queue1){
        s1 += n;
    }
    for (int n : queue2){
        s2 += n;
    }
    
    int answer = solve(queue1, queue2, s1, s2);
    

    return answer;
}