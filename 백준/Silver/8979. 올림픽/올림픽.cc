#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country{
    int number;
    int gold;
    int silver;
    int bronze;

    Country(){
        number = 0;
        gold = 0;
        silver = 0;
        bronze = 0;
    }
    Country(int n, int g, int s, int b){
        number = n;
        gold = g;
        silver = s;
        bronze = b;
    }
};

bool compare(Country a, Country b){
    if (a.gold != b.gold){
        return a.gold > b.gold;
    }
    if (a.silver != b.silver){
        return a.silver > b.silver;
    }
    return a.bronze > b.bronze;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<Country> countries;

    for (int i = 0; i < N; i++){
        int n, g, s, b;
        cin >> n >> g >> s >> b;
        countries.push_back(Country(n, g, s, b));
    }
    sort(countries.begin(), countries.end(), compare);

    int trg = 0;
    for (trg; trg < N; trg++){
        if (countries[trg].number == K){
            break;
        }
    }
    int answer = trg + 1;

    Country cur = countries[trg];
    trg--;
    while (trg >= 0){
        Country before = countries[trg];
        if (cur.gold == before.gold && cur.silver == before.silver && cur.bronze == before.bronze){
            answer--;
            trg--;
        }
        else{
            break;
        }
    }

    cout << answer;
}