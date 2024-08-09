#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

struct House {
    int r, c;
};
struct Chicken {
    int r, c;
    bool visited;
};
int N, M;
int minCityDistance = INT_MAX;
vector<House> house;
vector<Chicken> chicken;

void calculateDistance() {
    int cityDistance = 0;
    for (int i=0; i<house.size(); i++) {
        int minHouseDistance = INT_MAX;
        for (int j=0; j<chicken.size(); j++) {
            if (chicken[j].visited) {
                int houseDistance = abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c);
                if (houseDistance < minHouseDistance) {
                    minHouseDistance = houseDistance;
                }
            }
        }
        cityDistance += minHouseDistance;
    }
    if (cityDistance < minCityDistance) {
        minCityDistance = cityDistance;
    }
}

void selectChicken(int index, int count) {
    if (count == M) {
        calculateDistance();
    }
    for (int i=index; i<chicken.size(); i++) {
        if (!chicken[i].visited) {
            chicken[i].visited = true;
            selectChicken(i, count + 1);
            chicken[i].visited = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    int flag;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &flag);
            if (flag == 1) { house.push_back({i, j}); }
            else if (flag == 2) { chicken.push_back({i, j, false}); }
        }
    }

    selectChicken(0, 0);
    printf("%d", minCityDistance);
}