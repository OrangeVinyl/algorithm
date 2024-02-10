#include <bits/stdc++.h>
using namespace std;

int t, m, n, k;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool visited[51][51];
int maps[51][51];

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int p = 0; p < 4; p++) {
        int ny = y + dy[p];
        int nx = x + dx[p];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (!visited[ny][nx] && maps[ny][nx] == 1) dfs(ny,nx);
    }
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> m >> n >> k;

        memset(maps, 0, sizeof(maps));
        memset(visited, false, sizeof(visited));
        
        for (int j = 0; j < k; j++) {
            int jx, jy;
            cin >> jx >> jy;
            maps[jy][jx] = 1;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (!visited[i][j] && maps[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}