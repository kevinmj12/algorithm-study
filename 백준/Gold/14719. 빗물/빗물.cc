#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);

    int highestIdx = -1;
    int highest = 0;

    for (int i = 0; i < W; i++){
        cin >> blocks[i];
        if (blocks[i] > highest){
            highest = blocks[i];
            highestIdx = i;
        }
    }

    vector<int> leftBlocks;
    int leftHighest = 0;
    for (int i = 0; i < highestIdx; i++){
        if (blocks[i] > leftHighest){
            leftBlocks.push_back(i);
            leftHighest = blocks[i];
        }
        else if (blocks[i] == leftHighest){
            leftBlocks.push_back(i);
        }
    }

    vector<int> rightBlocks;
    int rightHighest = 0;
    for (int i = W-1; i > highestIdx; i--){
        if (blocks[i] > rightHighest){
            rightBlocks.push_back(i);
            rightHighest = blocks[i];
        }
        else if (blocks[i] == rightHighest){
            rightBlocks.push_back(i);
        }
    }

    int answer = 0;

    leftBlocks.push_back(highestIdx);
    for (int i = 0; i < leftBlocks.size()-1; i++){
        int start = leftBlocks[i];
        int end = leftBlocks[i+1];
        int height = min(blocks[start], blocks[end]);

        for (int j = start+1; j <= end-1; j++){
            answer += height - blocks[j];
        }
    }

    rightBlocks.push_back(highestIdx);
    for (int i = 0; i < rightBlocks.size()-1; i++){
        int start = rightBlocks[i];
        int end = rightBlocks[i+1];
        int height = min(blocks[start], blocks[end]);

        for (int j = start-1; j >= end+1; j--){
            answer += height - blocks[j];
        }
    }

    cout << answer;
    return 0;
}