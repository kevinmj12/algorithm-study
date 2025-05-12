class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        
        int p = (n-1) / w;
        int r = (n-1) % w;
        boolean dir = true;
        
        // 역방향
        if (p % 2 == 1){
            dir = false;
        }
        
        int np = (num-1) / w;
        int nr = (num-1) % w;
        
        // 역방향
        if (np % 2 == 1){
            nr = w-1-nr;
        }
        
        answer = p - np;
        
        if (dir){
            if (r >= nr){
                answer++;
            }
        }
        else{
            if (r >= (w-1-nr)){
                answer++;
            }
        }

        
        return answer;
    }
}