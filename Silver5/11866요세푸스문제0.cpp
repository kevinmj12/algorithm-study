#include <iostream>
#include <vector>


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    std::vector<int> num;
    std::vector<int> answer;
    for (int i = 1; i < n+1; i++){
        num.push_back(i);
    }
    int j = 1;
    
    while (!num.empty()){
        if (j % k == 0){
            answer.push_back(num.front());
            num.erase(num.begin());
        }
        else{
            num.push_back(num.front());
            num.erase(num.begin());
        }
        j++;
        
        // for (int l = 0; l < num.size(); l++){
        //     printf("%d", num[l]);
        // }
        // printf("\n");
    }
    printf("<");
    for (int i = 0; i < n; i++){
        printf("%d", answer[i]);
        if (i < n-1){
            printf(", ");
        }
    }
    printf(">");
}