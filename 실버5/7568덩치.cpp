#include <iostream>
#include <vector>
using namespace std;

vector<int> heightList;
vector<int> weightList;
vector<int> rankList;

void sortRank(){
    for (int i = 0; i < rankList.size(); i++){
        for (int j = 0; j < rankList.size(); j++){
            if (heightList[i] < heightList[j]){
                if (weightList[i] < weightList[j]){
                    rankList[i]++;
                }
            }
        }
    }

    for (int i = 0; i < rankList.size(); i++){
        printf("%d\n", rankList[i]);
    }
}

int main(){
    int tCase;
    scanf("%d", &tCase);
    for (int t = 0; t < tCase; t++){
        int height, weight;
        scanf("%d %d", &height, &weight);

        heightList.push_back(height);
        weightList.push_back(weight);
        rankList.push_back(1);
    }

    sortRank();
}