import java.util.*;
import java.io.*;

class Solution {   
    public int[][] dp = new int[41][121];
    
    public int solution(int[][] info, int n, int m) {
        int answer = n;
        
        for (int i = 0; i <= info.length; i++){
            for (int j = 0; j < m; j++){
                dp[i][j] = n;
            }
        }
        dp[0][0] = 0;
        
        for (int i = 1; i <= info.length; i++){
            int a = info[i-1][0];
            int b = info[i-1][1];
            
            for (int j = 0; j < m; j++){
                dp[i][j] = Math.min(dp[i][j], dp[i-1][j]+a);
                if (j + b < m){
                    dp[i][j + b] = Math.min(dp[i][j + b], dp[i - 1][j]);
                }
            }
        }
        
        for (int j = 0; j < m; j++){
            answer = Math.min(answer, dp[info.length][j]);
        }
        if (answer == n){
            return -1;
        }
                
        return answer;
    }
}
