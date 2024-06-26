#include <iostream>
#include <string>

int main(){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    int* brokenButton = new int[M];
    int checkNumber = 0;
    int plusAns = 2147483647, minusAns = 2147483647;

    for (int i = 0; i < M; i++){
        int inputNum;
        scanf("%d", &inputNum);
        brokenButton[i] = inputNum;
        if (inputNum > 0){
            checkNumber++;
        }
    }
    
    if (M == 10){
        printf("%d", abs(100-N));
        return 0;
    }
    if (checkNumber == 9){
        if (abs(100-N) < N){
            printf("%d", abs(100-N));
        }
        else{
            printf("%d", N+1);
        }
        return 0;
    }
    
    
    int tryCount = 0;
    while (abs(N-100) > tryCount){
        bool plusSuccess = true;
        std::string tmp1 = std::to_string(N+tryCount);
        for (int i = 0; i < M; i++){
            for (int j = 0; j < tmp1.size(); j++){
                if (brokenButton[i] == tmp1[j]-'0'){
                    plusSuccess = false;
                    break;
                }
            }
        }
        if (plusSuccess){
            plusAns = std::to_string(N+tryCount).length()+tryCount;
        }

        
        
        if (N-tryCount >= 0){
            bool minusSuccess = true;
            std::string tmp2 = std::to_string(N-tryCount);
            for (int i = 0; i < M; i++){
                for (int j = 0; j < tmp2.size(); j++){
                    if (brokenButton[i] == tmp2[j]-'0'){
                        minusSuccess = false;
                        break;
                    }
                }
            }
            if (minusSuccess){
                minusAns = std::to_string(N-tryCount).length()+tryCount;
            }
        }
        if (plusAns < 2147483647 || minusAns < 2147483647){
            if (abs(N-100) <= plusAns && abs(N-100) <= minusAns){
                printf("%d", abs(N-100));
            }
            else if (plusAns < minusAns){
                printf("%d", plusAns);
            }
            else{
                printf("%d", minusAns);
            }
            return 0;
        }
        tryCount++;
    }
    printf("%d", abs(N-100));
    
}

