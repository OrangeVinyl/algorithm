#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int n, m, a[8][8], visited[8][8], ret;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
// 벽이 들어갈 수 있는 후보군
vector<pair<int, int>> wallList;
vector<pair<int, int>> virusList;

void dfs(int y, int x) {
  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] ||
        a[ny][nx] == 1)
      continue;
    visited[ny][nx] = 1;
    dfs(ny, nx);
  }
}

int logic() {
  memset(visited, 0, sizeof(visited));

  for (pair<int, int> t : virusList) {
    visited[t.first][t.second] = 1;
    dfs(t.first, t.second);
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0 && !visited[i][j]) cnt++;
    }
  }

  return cnt;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 2) virusList.push_back({i, j});
      if (a[i][j] == 0) wallList.push_back({i, j});
    }
  }

  // 벽 후보군에서 3개의 '조합' 생성하기
  for (int i = 0; i < wallList.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < j; ++k) {
        a[wallList[i].first][wallList[i].second] = 1;
        a[wallList[j].first][wallList[j].second] = 1;
        a[wallList[k].first][wallList[k].second] = 1;

          // 최댓값 비교
          ret = max(ret, logic());

          // 원상 복구
          a[wallList[i].first][wallList[i].second] = 0;
          a[wallList[j].first][wallList[j].second] = 0;
          a[wallList[k].first][wallList[k].second] = 0;
      }
    }
  }

  cout << ret; 
}