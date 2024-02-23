#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int INF = 987654321;
int r, c, jy, jx, y, x, ret, fire_check[1004][1004], j_visited[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

char a[1004][1004];

bool in(int a, int b) { return a >= 0 && a < r && b >= 0 && b < c; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // 초기화
  queue<pair<int, int>> q;
  fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

  // init
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    
      if (a[i][j] == 'F') {
        fire_check[i][j] = 1;
        q.push({i, j});
      } 
      if (a[i][j] == 'J') {
        jy = i;
        jx = j;
      }
    }
  }

  // 화재 BFS(최단거리)
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (!in(ny, nx)) continue;
      if (fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;

      fire_check[ny][nx] = fire_check[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // 지훈 BFS(최단거리)
  j_visited[jy][jx] = 1;
  q.push({jy, jx});
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    // 탈출 조건
    if (x == c - 1 || y == r - 1 || x == 0 || y == 0) {
      ret = j_visited[y][x];
      break;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (!in(ny, nx)) continue;
      if (j_visited[ny][nx] || a[ny][nx] == '#') continue;
      // 불이 지훈이보다 더 빠르면 못간다 (최단거리를 구한거기 떄문에 작은게
      // 빠른 것!)
      if (j_visited[y][x] + 1 >= fire_check[ny][nx]) continue;

      j_visited[ny][nx] = j_visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // print
  if (ret != 0)
    cout << ret;
  else
    cout << "IMPOSSIBLE";

  return 0;
}