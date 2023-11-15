#include <iostream>

bool students[31] = {false};
int main(){
    for (int i = 0; i < 28; i++){
        int k;
        scanf("%d", &k);
        students[k] = true;
    }
    for (int i = 1; i < 31; i++){
        if (!students[i]){
            printf("%d\n", i);
        }
    }
}
    