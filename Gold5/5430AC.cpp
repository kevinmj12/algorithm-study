#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void AC(string command, vector<int> numList){
    bool isReversed = false;
    int start = 0;
    int end = numList.size();
    for (int i = 0; i < command.size(); i++){
        // R 명령
        // 실제로 뒤집는 것은 매우 오래 걸리므로 isReversed에 reverse 여부를 저장
        if (command[i] == 'R'){
            isReversed = !isReversed;
        }
        // D 명령
        else if (command[i] == 'D'){
            // numList에 아무 수도 없는 경우 에러
            if (start >= end){
                cout << "error\n";
                return;
            }
            // 뒤집어지지 않은 경우
            if (!isReversed){
                start++;
            }
            // 뒤집어진 경우
            else{
                end--;
            }
        }
    }
    
    cout << "[";
    if (isReversed == false){
        for (int i = start ; i <= end-1; i++){
            cout << numList[i];
            if (i < end-1){
                cout << ",";
            }
        }
    }
    else{
        for (int i = end-1; i >= start; i--){
            cout << numList[i];
            if (i > start){
                cout << ",";
            }
        }
    }
    cout << "]\n";
    return;
}

int main(){
    ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;
    
    while (T--){
        // 명령을 입력받음
        string command;
        cin >> command;

        // 배열에 들어있는 수 개수를 입력받음
        int n;
        cin >> n;

        // 배열을 입력받음
        string inputArr;
        cin >> inputArr;

        // 입력받은 배열을 numList(vector)에 넣음
        vector<int> numList;
        inputArr = inputArr.substr(1, inputArr.length()-2);
        

        int i = 0;
        while (i < inputArr.length()){
            int start;
            int length = 1;
            if (inputArr[i] != ','){
                start = i;
                while (inputArr[i+1] != ',' && i+1 < inputArr.length()){
                    i++;
                    length++;
                }
                numList.push_back(stoi(inputArr.substr(start, length)));
            }
            i++;
        }

        // 명령을 실행
        AC(command, numList);
    }
}