#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[50];
bool increase[50];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        
        bool infinite = false;
        cin >> arr[0];
        arr[0] *= 2;
        
        if (n == 1){
            cout << 0 <<"\n";
            continue;
        }
        
        for (int i = 1; i < n; i++){
            cin >> arr[i];
            arr[i] *= 2;
            if (arr[i-1] == arr[i]){
                infinite = true;
            }
            else if (arr[i-1] < arr[i]) {
               	increase[i-1] = true;
            }
            else{
                increase[i-1] = false;
            }
        }
        
        if (infinite){
            cout << -1 << "\n";
            continue;
        }
        
        vector<pair<int, int>> scope;
        for (int i = 0; i < n-1; i++){
            int left = arr[i];
            bool state = increase[i];
            while (i+1 < n-1 && increase[i+1] == state){
                i++;
            }
            int right = arr[i+1];
            if (i < n-2){
                if (state){
                    right--;
                }
                else{
                    right++;
                }
            }
            scope.push_back({min(left, right), max(left, right)});
        }
    	
        sort(scope.begin(), scope.end());
        int numY = 1;
        int answer = 1;
        int right = scope[0].second;
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(right);
        
        for (int i = 1; i < scope.size(); i++){
            int a = scope[i].first;
            int b = scope[i].second;
            if (a <= right){
                numY++;
                q.push(b);
                right = q.top();
            }
            else {
                q.push(b);
                while (q.top() < a){
                    q.pop();
                   	numY--;
                }
                right = q.top(); 
                numY++;
            }
            answer = max(answer, numY);
        }
    	
        cout << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}