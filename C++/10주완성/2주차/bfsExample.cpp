#include <bits/stdc++.h>
using namespace std;

int n, m, ey, ex, nx, ny, sy, sx, y, x;
bool visited[104][104];
int a[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int,int>> q;

    visited[sy][sx] = true;
    q.push({sy,sx});
    while(q.size()) {
        tie(y,x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = y + dy[i];
            int ny = y + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return 0;
}