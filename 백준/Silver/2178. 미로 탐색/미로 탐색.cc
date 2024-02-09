#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[101][101];
int map[101][101];

int n,m;

void bfs() {
    queue<pair<int,int>> q;

    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || !map[ny][nx]) continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }

    cout << visited[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); ++j) {
            map[i][j] = line[j] - '0';
        }
    }

    bfs();

    return 0;
}