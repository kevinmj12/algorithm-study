#include <iostream>

int main(){
    bool plusNumList[1000001] = {false};
    bool minusNumList[1000001] = {false};
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        int j;
        scanf("%d", &j);
        if (j >= 0){
            plusNumList[j] = true;
        }
        else{
            minusNumList[-j] = true;
        }
    }
    for (int k = 1000000; k > 0; k--){
        if (minusNumList[k]){
            printf("%d\n", -k);
        }
    }
    for (int l = 0; l < 1000001; l++){
        if (plusNumList[l]){
            printf("%d\n", l);
        }
    }
}