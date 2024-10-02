import java.util.*;

class Solution {
    public static int lower_bound(ArrayList<String> arr, String key) {
        int left = 0;
        int right = arr.size()-1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (arr.get(mid).compareTo(key) < 0){
                left = mid + 1;
            }        
            else{
                right = mid - 1;
            }
        }
    
        return left;
    }

    public static int upper_bound(ArrayList<String> arr, String key) {
        int left = 0;
        int right = arr.size()-1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (arr.get(mid).compareTo(key) <= 0){
                left = mid + 1;
            }        
            else{
                right = mid - 1;
            }
        }
    
        return left;
    }
    
    public int[] solution(String[] words, String[] queries) {
        int[] answer = new int[queries.length];
        
        ArrayList<String>[] originWords = new ArrayList[10001];
        ArrayList<String>[] reverseWords = new ArrayList[10001];
        
        for (int i = 0; i < 10001; i++) {
            originWords[i] = new ArrayList<>();
            reverseWords[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < words.length; i++){
            originWords[words[i].length()].add(words[i]);
            String reversed = new StringBuilder(words[i]).reverse().toString();
            reverseWords[words[i].length()].add(reversed);
        }
        
        for (int i = 0; i < 10001; i++){
            Collections.sort(originWords[i]);
            Collections.sort(reverseWords[i]);
        }
        
        for (int i = 0; i < queries.length; i++){
            String target = queries[i];
            String start, end;
            int tmpIdx = 0;
            // 접두사인 경우
            if (target.charAt(0) == '?'){
                target = new StringBuilder(target).reverse().toString();
            
                while (target.charAt(tmpIdx) != '?'){
                    tmpIdx++;
                }
                start = target.substring(0, tmpIdx) + "a".repeat(target.length()-tmpIdx);
                end = target.substring(0, tmpIdx) + "z".repeat(target.length()-tmpIdx);
                
                // reverseWords와 비교
                answer[i] += upper_bound(reverseWords[target.length()], end) - lower_bound(reverseWords[target.length()], start);
            }
            // 접미사인 경우
            else{
                while (target.charAt(tmpIdx) != '?'){
                    tmpIdx++;
                }
                start = target.substring(0, tmpIdx) + "a".repeat(target.length()-tmpIdx);
                end = target.substring(0, tmpIdx) + "z".repeat(target.length()-tmpIdx);
                
                // words와 비교
                answer[i] += upper_bound(originWords[target.length()], end) - lower_bound(originWords[target.length()], start);
            }
        }
        
        return answer;
    }
}