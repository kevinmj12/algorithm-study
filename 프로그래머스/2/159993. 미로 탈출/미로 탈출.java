import java.util.*;
import java.io.*;

class Solution {
    char[][] graph = new char[100][100];
    boolean[][] visited = new boolean[100][100];
    int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public class Point{
        int y;
        int x;
        
        Point(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    public void resetVisited(int r, int c){
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                visited[i][j] = false;
            }
        }
    }
    
    public int bfs(Point s, Point e, int r, int c){
        resetVisited(r, c);
        
        Queue<Point> q = new LinkedList();
        q.add(s);
        visited[s.y][s.x] = true;
        int rtn = 0;
        
        while (!q.isEmpty()){            
            int size = q.size();
            for (int i = 0; i < size; i++){
                Point cur = q.poll();
                if (cur.y == e.y && cur.x == e.x){
                    return rtn;
                }
                
                for (int d = 0; d < 4; d++){
                    int nextY = cur.y+dir[d][0];
                    int nextX = cur.x+dir[d][1];
                    
                    if (nextY < 0 || nextY >= r || nextX < 0 || nextX >= c || graph[nextY][nextX] == 'X' || visited[nextY][nextX]){
                        continue;
                    }
                    Point next = new Point(nextY, nextX);
                    q.add(next);
                    visited[nextY][nextX] = true;
                }
            }
            rtn++;
        }
        
        
        return -1;
    }
    
    public int solution(String[] maps) {
        int answer = 0;
        
        Point start = new Point(0, 0);
        Point lever = new Point(0, 0);
        Point exit = new Point(0, 0);
        
        for (int i = 0; i < maps.length; i++){
            for (int j = 0; j < maps[i].length(); j++){
                graph[i][j] = maps[i].charAt(j);
                
                if (graph[i][j] == 'S'){
                    start = new Point(i, j);
                }
                if (graph[i][j] == 'L'){
                    lever = new Point(i, j);
                }
                if (graph[i][j] == 'E'){
                    exit = new Point(i, j);
                }
            }
        }
        
        // 출발지에서 레버로 이동
        int a = bfs(start, lever, maps.length, maps[0].length());
        
        // 레버에서 도착지로 이동
        int b = bfs(lever, exit, maps.length, maps[0].length());
        
        if (a == -1 || b == -1){
            return -1;
        }
        
        answer = a + b;
        
        return answer;
    }
}