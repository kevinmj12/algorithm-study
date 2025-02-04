#include <iostream>
#include <queue>
using namespace std;

bool books[1001];

void resetBooks(int n){
    for (int i = 1; i <= n; i++){
        books[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        resetBooks(n);
        int answer = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            pq.push({b, a});
        }

        while (!pq.empty()){
            int start = pq.top().second;
            int end = pq.top().first;
            pq.pop();

            for (int i = start; i <= end; i++){
                if (!books[i]){
                    books[i] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << "\n";
    }
}

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #define MAX 1000
// using namespace std;
// typedef pair<int, int> pii;
// int T, N, M;
// bool isUsed[MAX + 1];
// void init() {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ios_base::sync_with_stdio(0);
// }

// bool compare(pii num1, pii num2) {
//     if (num1.second == num2.second) return num1.first < num2.first;
//     return num1.second < num2.second;
// }

// int countMaxStudents(vector<pii> nums) {
//     int cnt = 0;
//     sort(nums.begin(), nums.end(), compare);
//     for (int i = 0; i < nums.size(); i++){
//         cout << nums[i].first << " " << nums[i].second << endl;

//     }
//     for (int idx = 0; idx < M; idx++) {
//         int start = nums[idx].first;
//         int end = nums[idx].second;
//         for (int num = start; num <= end; num++) {
//             if (!isUsed[num]) {
//                 isUsed[num] = true;
//                 cnt++;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// int main() {
//     init();
//     cin >> T;
//     while (T--) {
//         cin >> N >> M;
//         memset(isUsed, 0, sizeof(isUsed));
//         vector<pii> nums;
//         for (int idx = 0; idx < M; idx++) {
//             int start, end;
//             cin >> start >> end;
//             nums.push_back(pii(start, end));
//         }
//         int ans = countMaxStudents(nums);
//         cout << ans;
//     }
//     return 0;
// }