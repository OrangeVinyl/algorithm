#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 301

int l, tc, sx, sy, tx, ty;
int c[MAX][MAX], v[MAX][MAX];
int dy[8] = {2,1,-1,-2,-2,-1,1,2}, dx[8] = {1,2,2,1,-1,-2,-2,-1};

void bfs() {
    queue<pair<int,int> > q;
    q.push({sx,sy});
    v[sx][sy] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == tx && y == ty) {
            cout << c[x][y] << '\n';
        }

        for (int i = 0 ; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if (!v[nx][ny]) {
                q.push({nx, ny});
                v[nx][ny] = 1;
                c[nx][ny] = c[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> tc;

    while (tc--) {
        cin >> l;
        cin >> sx >> sy;
        cin >> tx >> ty;
        memset(c,0,sizeof(c)); memset(v,0,sizeof(v));
        bfs();
    }

    return 0;
}
