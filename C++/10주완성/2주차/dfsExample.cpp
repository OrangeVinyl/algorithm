#include <bits/stdc++.h>
using namespace std;

int n, m, k, y, x, ret, ny, nx, t;

bool visited[104][104];
int a[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0 , -1};

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                ret++;
                dfs(i,j);
            }
        }
    }

    cout << ret <<'\n';
    return 0;
}