#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    deque<pair<int, int>> deq;

    int N;
    cin >> N;


    for (int i = 1; i <= N; i++){
        int a;
        cin >> a;

        deq.push_back({a, i});
    }

    while(!deq.empty()){
        int v = deq.front().first;
        cout << deq.front().second << " ";
        deq.pop_front();


        if (!deq.empty()){
            if (v > 0){
                v--;
                while (v--){
                    deq.push_back(deq.front());
                    deq.pop_front();
                }
            }
            else{
                while (v++){
                    deq.push_front(deq.back());
                    deq.pop_back();
                }
            }
        }
    }
}