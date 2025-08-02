import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();
        int score = 0;
        int maxScore = 0;

        for (int i = 0; i < str.length(); i++){
            switch (str.charAt(i)) {
                case '[':
                    score += 3;
                    break;
                case ']':
                    score -= 3;
                    break;
                case '{':
                    score += 2;
                    break;
                case '}':
                    score -= 2;
                    break;
                case '(':
                    score++;
                    break;
                case ')':
                    score--;
                    break;
                default:
                    maxScore = Math.max(maxScore, score);
            }
        }
        System.out.println(maxScore);
    }
}