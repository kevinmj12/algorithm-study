#include <iostream>

int main(){
    int n;
    scanf("%d", &n);
    int countTwo = 0, countFive = 0;
    for (int i = 1; i < n+1; i++){
        int k = i;
        while (true){
            if (k % 2 == 0){
                countTwo++;
                k /= 2;
            }
            else{
                break;
            }
        }
        while (true){
            if (k % 5 == 0){
                countFive++;
                k /= 5;
            }
            else{
                break;
            }
        }
        
    }
    int answer = countTwo<countFive?countTwo:countFive;
    
    printf("%d", answer);
}