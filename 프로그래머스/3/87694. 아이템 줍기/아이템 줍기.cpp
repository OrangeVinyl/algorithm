#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int root[101][101];

int answer = 99999;

void dfs(int x, int y, int answer_x, int answer_y, int count) {
    if (x == answer_x && y == answer_y) {
        answer = min(answer,count);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (root[nx][ny] == 8) {
            // 다시 탐색하지 못하게 0 처리
            root[nx][ny] = 0;
            dfs(nx, ny, answer_x, answer_y, count + 1);
            // 다른 방향을 고려해 원상복구
            root[nx][ny] = 8;
        } 
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    
    // rectangle에 들어가는 영역 전부 8로 채우기
    for(int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0]*2; j <= rectangle[i][2]*2; j++) {
            for (int k = rectangle[i][1]*2; k <= rectangle[i][3]*2; k++) {
                root[j][k] = 8;
            }
        }
    }
    
    // 경로를 제외한 나머지 부분 0으로 변환
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0]*2 + 1; j <= rectangle[i][2]*2 - 1; j++) {
            for (int k = rectangle[i][1]*2 + 1; k <= rectangle[i][3]*2 - 1; k++) {
                root[j][k] = 0;
            }
        }
    }
    
    root[characterX][characterY] = 1;
    
    dfs(characterX, characterY, itemX, itemY, 0);
    
    return answer / 2;
}