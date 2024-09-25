#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> plusBooks;
vector<int> minusBooks;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int book;
        cin >> book;
        if (book > 0){
            plusBooks.push_back(book);
        }
        else{
            minusBooks.push_back(-book);
        }
    }
    
    sort(plusBooks.begin(), plusBooks.end(), cmp);
    sort(minusBooks.begin(), minusBooks.end(), cmp);
    
    int answer = 0;
    for (int i = 0; i < plusBooks.size(); i+=m){
        answer += plusBooks[i] * 2;
    }

    for (int i = 0; i < minusBooks.size(); i+=m){
        answer += minusBooks[i] * 2;
    }

    int maxBook = 0;
    if (!plusBooks.empty()){
        maxBook = max(maxBook, plusBooks[0]);
    }
    if (!minusBooks.empty()){
        maxBook = max(maxBook, minusBooks[0]);
    }

    answer -= maxBook;
    cout << answer;
}