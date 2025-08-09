import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        int longWallet = Math.max(wallet[0], wallet[1]);
        int shortWallet = Math.min(wallet[0], wallet[1]);
        
        int longBill = Math.max(bill[0], bill[1]);
        int shortBill = Math.min(bill[0], bill[1]);
        
        while (!(longWallet >= longBill && shortWallet >= shortBill)){
            answer++;
            longBill /= 2;
            if (shortBill > longBill){
                int tmp = longBill;
                longBill = shortBill;
                shortBill = tmp;
            }
        }
        
        return answer;
    }
}