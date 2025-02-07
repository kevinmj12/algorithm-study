import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static boolean[][] graph;
    static boolean[] visited;

    public static void resetVisited(int n){
        for (int i = 1; i <= n; i++){
            visited[i] = false;
        }
    }
    
    public static void dfs(int cur, int n){
        System.out.print(cur);
        System.out.print(" ");
        visited[cur] = true;

        for (int i = 1; i <= n; i++){
            if (graph[cur][i] && !visited[i]){        
                dfs(i, n);
            }
        }
    }

    public static void bfs(int start, int n){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;

        while (!q.isEmpty()){
            int cur = q.poll();
            System.out.print(cur);
            System.out.print(" ");

            for (int i = 1; i <= n; i++){
                if (graph[cur][i] && !visited[i]){
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        
        graph = new boolean[n+1][n+1];

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                graph[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            graph[a][b] = true;
            graph[b][a] = true;
        }
        
        br.close();

        visited = new boolean[n+1];
        resetVisited(n);
        
        dfs(v, n);
        System.out.println();
        resetVisited(n);
        bfs(v, n);
    }
}