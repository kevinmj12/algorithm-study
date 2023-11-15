#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for (int tcase = 0; tcase < T; tcase++){
        int N, M;
        scanf("%d %d", &N, &M);

        queue<int> docs;
        queue<int> importance;
        for (int doc = 0; doc < N; doc++){
            int i;
            scanf("%d", &i);
            docs.push(doc);
            importance.push(i);
        }
        int cnt = 1;
        while (true){
            bool isMostImportant = true;
            int key = importance.front();
            for (int doc = 0; doc < docs.size(); doc++){
                // 큐를 한 바퀴 돌면서 중요도 체크
                if (key < importance.front()){
                    isMostImportant = false;
                }
                docs.push(docs.front());
                importance.push(importance.front());
                docs.pop();
                importance.pop();
            }
            if (isMostImportant){
                // 제일 중요한 문서면 pop
                if (docs.front() == M){
                    printf("%d\n", cnt);
                    break;
                }
                docs.pop();
                importance.pop();
                cnt++;
            }
            else{
                // 이외의 경우 뒤로 밂
                docs.push(docs.front());
                importance.push(importance.front());
                docs.pop();
                importance.pop();
            }
        }
    }

    
}