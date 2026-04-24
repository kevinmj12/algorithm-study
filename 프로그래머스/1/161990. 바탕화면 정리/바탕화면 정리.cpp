#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int y1 = wallpaper.size();
    int x1 = wallpaper[0].length();
    int y2 = 0;
    int x2 = 0;
    
    for (int i = 0; i < wallpaper.size(); i++){
        for (int j = 0; j < wallpaper[0].length(); j++){
            if (wallpaper[i][j] == '#'){
                y1 = min(y1, i);
                x1 = min(x1, j);
                y2 = max(y2, i+1);
                x2 = max(x2, j+1);
            }
        }
    }
    
    answer = {y1, x1, y2, x2};
    
    return answer;
}