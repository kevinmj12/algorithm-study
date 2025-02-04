#include <iostream>

int main(){
    int N, M, B;
    scanf("%d %d %d", &N, &M, &B);

    int land[N][M];
    int lowLand = 256;
    int highLand = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int h;
            scanf("%d", &h);
            land[i][j] = h;
            if (h < lowLand){
                lowLand = h;
            }
            if (h > highLand){
                highLand = h;
            }
        }
    }
    int answer = 2147483647;
    int height;
    while (highLand >= lowLand){
        int add = 0;
        int remove = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                int tmp = highLand - land[i][j];
                if (tmp >= 0){
                    add += tmp;
                }
                else{
                    remove += -1*(tmp);
                }
            }
        }   
        if (add > remove + B){
            highLand--;
            continue;
        }
        else{
            if (answer > add + (remove*2)){
                answer = add + (remove*2);
                height = highLand;
            }
            highLand--;
        }
        
    }

    printf("%d %d", answer, height);
    
}