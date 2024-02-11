#include <bits/stdc++.h>
using namespace std;

int n, max_h, answer, cnt;
int visited[101][101];
int maps[101][101];

int dy[4] = {-1, 0 , 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int height) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (maps[ny][nx] > height && !visited[ny][nx]) dfs(ny, nx, height);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
            if (max_h < maps[i][j]) max_h = maps[i][j];
        }
    }

    for (int k = 0; k < max_h; k++) {
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maps[i][j] > k && !visited[i][j]) {
                    dfs(i,j,k);
                    cnt++;
                }
            }
        }

        if (cnt > answer) answer = cnt;
    } 

    cout << answer;
    
    return 0;
}