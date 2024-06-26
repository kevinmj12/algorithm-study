#include <iostream>
#include <vector>
#include <string>
using namespace std;

class set_{
    private:
        vector<int> v;

    public:
        void add(int x){
            for (int i = 0; i < v.size(); i++){
                if (x == v[i]){
                    return;
                }
            }
            v.push_back(x);
        }
        void remove(int x){
            for (int i = 0; i < v.size(); i++){
                if (x == v[i]){
                    v.erase(v.begin()+i);
                    return;
                }
            }
        }
        int check(int x){
            for (int i = 0; i < v.size(); i++){
                if (x == v[i]){
                    return 1;
                }
            }
            return 0;
        }
        void toggle(int x){
            for (int i = 0; i < v.size(); i++){
                if (x == v[i]){
                    v.erase(v.begin()+i);
                    return;
                }
            }
            v.push_back(x);
        }
        void all(){
            v = {};
            for (int i = 1; i <= 20; i++){
                v.push_back(i);
            }
        }
        void empty(){
            v = {};
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    set_ s = set_();

    int numOrders;
    cin >> numOrders;
    while (numOrders--){
        string order;
        cin >> order;
        if (order != "all" && order != "empty"){
            int x;
            cin >> x;

            if (order == "add"){
                s.add(x);      
            }
            else if (order == "remove"){
                s.remove(x);
            }
            else if (order == "check"){
                int tmp = s.check(x);
                cout << tmp << "\n";
            }
            else{
                s.toggle(x);
            }
        }
        else{
            if (order == "all"){
                s.all();
            }
            else if (order == "empty"){
                s.empty();
            }
        }
    }
}