import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int [queries.length];
        
        int[][] graph = new int[rows+1][columns+1];
        
        for (int i = 1; i <= rows; i++){
            for (int j = 1; j <= columns; j++){
                graph[i][j] = ((i-1) * columns) + j;
                // System.out.print(graph[i][j]);
                // System.out.print(" ");
            }
            // System.out.println();
        }
        
        for (int i = 0; i < queries.length; i++){
            int y1 = queries[i][0];
            int x1 = queries[i][1];
            int y2 = queries[i][2];
            int x2 = queries[i][3];
                        
            // (2 2 5 4)
            int startVal = graph[y1][x1];
            int minVal = rows * columns;
            // (2 2) -> (5 2)
            for (int y = y1; y < y2; y++){
                graph[y][x1] = graph[y+1][x1];
                minVal = Math.min(minVal, graph[y][x1]);
            }
            // (5 2) -> (5 4)
            for (int x = x1; x < x2; x++){
                graph[y2][x] = graph[y2][x+1];
                minVal = Math.min(minVal, graph[y2][x]);
            }
            // (5 4) -> (2 4)
            for (int y = y2; y > y1; y--){
                graph[y][x2] = graph[y-1][x2];
                minVal = Math.min(minVal, graph[y][x2]);
            }
            // (2 4) -> (2 2)
            for (int x = x2; x > x1; x--){
                graph[y1][x] = graph[y1][x-1];
                minVal = Math.min(minVal, graph[y1][x]);
            }
            graph[y1][x1+1] = startVal;
            minVal = Math.min(minVal, graph[y1][x1+1]);
            
            answer[i] = minVal;
            
        }
        
        return answer;
    }
}