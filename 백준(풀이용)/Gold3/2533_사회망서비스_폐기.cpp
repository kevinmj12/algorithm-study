#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int parent[1000001];
int n;
int answer = 2147483647;

class Node {
	public:
		bool isEarlyAdapter;

		Node* left;
		Node* right;
        
    Node(bool b){
        isEarlyAdapter = b;
        
        left = NULL;
        right = NULL;
    }
};

void InsertNode(Node* root, int depth, int target, bool mustEA){
    // depth가 target의 부모일 때
    if (parent[target] == depth){
        // 부모가 얼리어답터인 경우 자식은 어느 쪽이든 상관없음
        if (root->isEarlyAdapter){
            // 바로 다음에 target이 insert되는 경우
            if (depth == target-1){
                root->left = new Node(true);
                root->right = new Node(false);
                return;
            }
            InsertNode(root->left, depth+1, target, false);
            if (root->right != NULL){
                InsertNode(root->right, depth+1, target, false);
            }
        }
        // 부모가 얼리어답터가 아닌 경우 자식은 반드시 얼리어답터여야 함
        else{
            // 바로 다음에 target이 insert되는 경우
            if (depth == target-1){
                root->left = new Node(true);
                return;
            }
            InsertNode(root->left, depth+1, target, true);
            if (root->right != NULL){
                InsertNode(root->right, depth+1, target, true);
            }
        }
    }
    // depth가 target-1일 때 (target이 insert될 차례일 때)
    else if (depth == target-1){
        // 반드시 얼리어답터여야 하는 경우 left에만 추가
        if (mustEA){
            root->left = new Node(true);
            return;
        }
        // 상관없는 경우 left, right에 모두 추가
        else{
            root->left = new Node(true);
            root->right = new Node(false);
            return;
        }
    }
    // 이외의 경우
    else{
        InsertNode(root->left, depth+1, target, mustEA);
        if (root->right != NULL){
            InsertNode(root->right, depth+1, target, mustEA);
        }
    }
}

void FindAnswer(Node* root, int total){
    // left가 NULL인 경우(마지막인 경우)
    if (root->left == NULL){
        // 0번 root가 true이므로 -1
        answer = min(answer, total - 1);
        return;
    }
    // 현재 노드가 얼리 어답터인경우
    if (root->isEarlyAdapter){
        FindAnswer(root->left, total+1);
        if (root->right != NULL){
            FindAnswer(root->right, total+1);
        }
    }
    // 현재 노드가 얼리 어답터가 아닌 경우
    else{
        FindAnswer(root->left, total);
        if (root->right != NULL){
            FindAnswer(root->right, total);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        parent[a] = b;
    }

    // root를 설정하고 트리를 제작
    Node* root = new Node(true);
    for (int i = 1; i <= n; i++){
        InsertNode(root, 0, i, false);
    }
    FindAnswer(root, 0);
    cout << answer;
}