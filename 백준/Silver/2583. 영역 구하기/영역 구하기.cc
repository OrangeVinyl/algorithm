#include <bits/stdc++.h>
using namespace std;

int m, n, k;

bool visited[101][101];
bool block[101][101];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<int> area;

int dfs(int y, int x) {
    visited[y][x] = true;
    int cnt = 1;
    
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (!block[ny][nx] && !visited[ny][nx]) {
        cnt += dfs(ny,nx);
      }
    }

    return cnt;
}

int main() {
  cin  >> m >> n >> k;

  for (int i = 0; i < k; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    for(int tx = lx; tx < rx; tx++) {
      for (int ty = ly; ty < ry; ty++) {
        block[ty][tx] = true;
      }
    }
  }

  for (int i = 0; i < m ; i++) {
    for (int j = 0; j < n ; j++) {
      // 방문하지 않은 경우 & 막히지 않은 경우
      if (!block[i][j] && !visited[i][j]) {
        area.push_back(dfs(i,j));
      }
    }
  }

  sort(area.begin(), area.end());

  cout << area.size() << '\n';

  for (int i : area) {
    cout << i << ' ';
  }

  return 0;
}