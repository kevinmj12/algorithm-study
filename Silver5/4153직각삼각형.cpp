#include <iostream>

int main(){
    while (true){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0){
            break;
        }else{
            int aa = a*a;
            int bb = b*b;
            int cc = c*c;
            if (aa+bb==cc || bb+cc==aa || cc+aa==bb){
                printf("right\n");
            }else{
                printf("wrong\n");
            }
        }
    }
    
}