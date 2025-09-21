#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    string name;
    map<string, int> leavesMap;
    vector<Node*> leavesVec;
    Node(string n){
        name = n;
    }
};

bool compare(Node* a, Node* b){
    return a->name < b->name;
}

void printAnswer(Node* node, int depth){
    if (node->name != "root"){
        for (int i = 0; i < (depth-1)*2; i++){
            cout << "-";
        }
        cout << node->name << "\n";
    }
    if (node->leavesVec.empty()){
        return;
    }
    sort(node->leavesVec.begin(), node->leavesVec.end(), compare);
    for (int i = 0; i < node->leavesVec.size(); i++){
        printAnswer(node->leavesVec[i], depth+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    Node root = Node("root");

    for (int i = 0; i < N; i++){
        int K;
        cin >> K;

        Node* cur = &root;
        for (int j = 0; j < K; j++){
            string str;
            cin >> str;

            if (cur->leavesMap.find(str) != cur->leavesMap.end()){
                cur = cur->leavesVec[cur->leavesMap[str]];
            }
            else{
                int size = cur->leavesVec.size();
                Node* leaf = new Node(str);
                cur->leavesVec.push_back(leaf);
                cur->leavesMap.insert({str, size});
                cur = cur->leavesVec[size];
            }
        }
    }

    printAnswer(&root, 0);
}