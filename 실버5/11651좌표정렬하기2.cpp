#include <iostream>

void bubbleSort(int* arrX, int* arrY, int n);
int partition(int* arrX, int* arrY, int left, int right);
void swap(int* arrX, int* arrY, int a, int b);
void quickSort(int* arrX, int* arrY, int left, int right);

int main(){
    int N;
    scanf("%d", &N);
    int *coordArrX = new int[N];
    int *coordArrY = new int[N];
    for (int i = 0; i < N; i++){
        scanf("%d %d", &coordArrX[i], &coordArrY[i]);
    }

    quickSort(coordArrX, coordArrY, 0, N-1);
    for (int i = 0; i < N; i++){
        printf("%d %d\n", coordArrX[i], coordArrY[i]);
    }
}

int partition(int* arrX, int* arrY, int left, int right){
    int mid = (left + right) / 2;
    swap(arrX, arrY, left, mid);

    int pivotX = arrX[left];
    int pivotY = arrY[left];
    int i = left, j = right;

    while (i < j){
        while (pivotY <= arrY[j]){
            if (pivotY == arrY[j]){
                if (pivotX < arrX[j]){
                    j--;
                }
                else{
                    break;
                }
            }
            else{
                j--;
            }
        }

        while (i < j && pivotY >= arrY[i]) {
            if (pivotY == arrY[i]){
                if (pivotX >= arrX[i]){
                    i++;
                }
                else{
                    break;
                }
            }
            else{
                i++;
            }            
        }
        swap(arrX, arrY, i, j);
    }

    swap(arrX, arrY, left, i);
    return i;
}

void swap(int* arrX, int* arrY, int a, int b){
    std::swap(arrX[a], arrX[b]);
    std::swap(arrY[a], arrY[b]);
}

void quickSort(int* arrX, int* arrY, int left, int right){
    if (left >= right){
        return;
    }
    int pi = partition(arrX, arrY, left, right);
    quickSort(arrX, arrY, left, pi-1);
    quickSort(arrX, arrY, pi+1, right);
}



