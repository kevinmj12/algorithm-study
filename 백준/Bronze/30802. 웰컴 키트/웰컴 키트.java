import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] sizes = new int[6];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++){
            sizes[i] = Integer.parseInt(st.nextToken());
        }

        int T, P;
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        
        int shirtsAnswer = 0;
        for (int i = 0; i < 6; i++){
            if (sizes[i] == 0){
                continue;
            }
            shirtsAnswer += ((sizes[i]-1) / T) + 1;
        }

        int penSetAnswer = N / P;
        int penAnswer = N % P;
        if (penAnswer == P){
            penAnswer = 0;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(shirtsAnswer + "\n");
        sb.append(penSetAnswer + " " + penAnswer);

        System.out.println(sb);
    }
}
