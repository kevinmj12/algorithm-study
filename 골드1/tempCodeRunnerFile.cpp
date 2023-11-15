else{
            while (true){
                if (func(N, mid-1) == k){
                    mid--;
                }
                else{
                    printf("%d", mid);
                    return 0;
                }
            }
        }