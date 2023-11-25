#include <iostream>
using namespace std;

int quickPartition(int* n, int start, int end){
    int pivot = n[start];
    int i = start;
    int j = end;

    while (i < j){
        while (pivot < n[j]){
            j--;
        }
        while (i < j && pivot >= n[i]){
            i++;
        }
        swap(n[i], n[j]);
    }
    n[start] = n[i];
    n[i] = pivot;
    return i;
}

void quickSort(int* n, int start, int end){
    if (start >= end){
        return;
    }
    int p = quickPartition(n, start, end);
    quickSort(n, start, p-1);
    quickSort(n, p+1, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int* numList = new int[N];
    for (int i = 0; i < N; i++){
        cin >> numList[i];
    }

    quickSort(numList, 0, N);

    for (int i = 0; i < N; i++){
        cout << numList[i] << " ";
    }
}