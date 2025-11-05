#include <iostream>
using namespace std;

int people[11];

int main(){
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++){
        int leftPeople;
        cin >> leftPeople;

        int idx = 1;
        int higherPeople = 0;
        while (higherPeople < leftPeople){
            if (people[idx] == 0){
                higherPeople++;
            }
            idx++;
        }
        while (people[idx] != 0){
            idx++;
        }
        people[idx] = i;
    }

    for (int i = 1; i <= N; i++){
        cout << people[i] << " ";
    }
}