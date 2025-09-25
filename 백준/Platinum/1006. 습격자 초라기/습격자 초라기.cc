#include <iostream>
#include <algorithm>
using namespace std;

int enemies[10001][3];
int dp[10001][4];

int main(){
    int T;
    cin >> T;

    while (T--){
        int N, W;
        cin >> N >> W;

        for (int i = 1; i <= N; i++){
            cin >> enemies[i][1];
        }
        for (int i = 1; i <= N; i++){
            cin >> enemies[i][2];
        }
        
        int answer = 20000;

        // a = 0: 1과 N이 합쳐지지 않음, 1: 위만 합쳐짐, 2: 아래만 합쳐짐, 3: 둘 다 합쳐짐
        for (int a = 0; a <= 3; a++){
            if ((a == 1 || a == 3) && enemies[1][1] + enemies[N][1] > W){
                continue;
            }
            else if ((a == 2 || a == 3) && enemies[1][2] + enemies[N][2] > W){
                continue;
            }

            // base case 
            dp[1][0] = 2;
            dp[1][1] = 2;
            dp[1][2] = 2;
            dp[1][3] = 2;
            if (a == 0 && enemies[1][1] + enemies[1][2] <= W){
                dp[1][3] = 1;
            }


            for (int i = 2; i <= N; i++){
                bool flag1 = enemies[i][1] + enemies[i-1][1] <= W;
                bool flag2 = enemies[i][2] + enemies[i-1][2] <= W;
                bool flag3 = enemies[i][1] + enemies[i][2] <= W;

                dp[i][0] = dp[i-1][3]+2;
                dp[i][1] = dp[i-1][3]+2;
                dp[i][2] = dp[i-1][3]+2;
                dp[i][3] = min(dp[i][1], dp[i][2]);
                
                if (i == 2){
                    if (a == 0){
                        if (flag1){
                            dp[i][1] = min(dp[i][1], dp[i-1][2]+1);
                        }
                        if (flag2){
                            dp[i][2] = min(dp[i][2], dp[i-1][1]+1);
                        }

                        dp[i][3] = min(dp[i][1], dp[i][2]);
                        if (flag3){
                            dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                        }
                        if (flag1 && flag2){
                            dp[i][3] = min(dp[i][3], dp[i-1][0]);
                        }
                    }
                    else if (a == 1){
                        if (flag2){
                            dp[i][2]--;
                        }
                        if (flag3){
                            dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                        }
                        dp[i][3] = min(dp[i][3], dp[i][2]);
                    }
                    else if (a == 2){
                        if (flag1){
                            dp[i][1]--;
                        }
                        if (flag3){
                            dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                        }
                        dp[i][3] = min(dp[i][3], dp[i][1]);
                    }
                    else if (a == 3){
                        if (flag3){
                            dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                        }
                    }
                    continue;
                }
                else if (i == N){
                    if (a == 0){
                        if (flag1){
                            dp[i][1] = min(dp[i][1], dp[i-1][2]+1);
                        }
                        if (flag2){
                            dp[i][2] = min(dp[i][2], dp[i-1][1]+1);
                        }

                        dp[i][3] = min(dp[i][1], dp[i][2]);
                        if (flag3){
                            dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                        }
                        if (flag1 && flag2){
                            dp[i][3] = min(dp[i][3], dp[i-1][0]);
                        }
                    }
                    else if (a == 1){
                        dp[i][1]--;
                        dp[i][2]--;
                        dp[i][3]--;
                        if (flag2){
                            dp[i][2] = min(dp[i][2], dp[i-1][1]);
                        }
                        dp[i][3] = min(dp[i][3], dp[i][2]);
                    }
                    else if (a == 2){
                        dp[i][1]--;
                        dp[i][2]--;
                        dp[i][3]--;
                        if (flag1){
                            dp[i][1] = min(dp[i][1], dp[i-1][2]);
                        }
                        dp[i][3] = min(dp[i][3], dp[i][1]);
                    }
                    else if (a == 3){
                        dp[i][3] = min(dp[i][3], dp[i-1][3]);
                    }
                    continue;
                }
                
                // 0

                // 1
                if (flag1){
                    dp[i][1] = min(dp[i][1], dp[i-1][2]+1);
                }
    
                // 2
                if (flag2){
                    dp[i][2] = min(dp[i][2], dp[i-1][1]+1);
                }
    
                // 3
                dp[i][3] = min(dp[i][1], dp[i][2]);
                if (flag3){
                    dp[i][3] = min(dp[i][3], dp[i-1][3]+1);
                }
                if (flag1 && flag2){
                    dp[i][3] = min(dp[i][3], dp[i-1][0]);
                }
            }

            answer = min(answer, dp[N][3]);
        }
        cout << answer << "\n";
    }
}