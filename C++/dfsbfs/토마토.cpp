#include <bits/stdc++.h>
using namespace std;

int m, n, answer, nx, ny;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void bfs(vector<vector<int>>& graph) {
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int k = 0; k < 4; k++) {
      ny = y + dy[k];
      nx = x + dx[k];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (graph[ny][nx] == 0) {
        graph[ny][nx] = graph[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  cin >> m >> n;
  vector<vector<int>> tomato(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 1) {
        q.push({i, j});
      }
    }
  }

  bfs(tomato);

  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (tomato[i][j] == 0) {
            cout << -1;
            return 0;
        }
        if (answer < tomato[i][j]) answer = tomato[i][j];
        
    }
  }

  cout << answer - 1;

  return 0;
}