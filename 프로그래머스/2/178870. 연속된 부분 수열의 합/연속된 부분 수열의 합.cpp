#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, (int)sequence.size()};
    
    int left = 0;
    int right = 0;
    
    int sum = sequence[left];
    while (right < sequence.size()){
        if (sum < k){
            right++;
            sum += sequence[right];
        }
        else if (sum > k){
            sum -= sequence[left];
            left++;
        }
        else{
            if (answer[1]-answer[0] > right - left){
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left];
            left++;
        }
    }
    
    return answer;
}