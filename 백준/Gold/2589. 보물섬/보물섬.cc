#include <bits/stdc++.h>
using namespace std;

int n, m, visited[54][54], _max;
char maps[54][54];
vector<pair<int,int>> landList;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

string s;

void bfs(int start_y, int start_x) {
  queue<pair<int,int>> q;
  q.push({start_y, start_x});
  visited[start_y][start_x] = 1;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visited[ny][nx]) continue;
      if (maps[ny][nx] == 'W') continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
      _max = max(_max, visited[ny][nx]);
    }
  }
}

int main() {
  // init
  cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      maps[i][j] = s[j];

      if (maps[i][j] == 'L') {
        landList.push_back({i,j});
      }
    }
  }

  // L인 모든 좌표에서 bfs
  for (int i = 0; i < landList.size(); i++) {
    memset(visited, 0, sizeof(visited));
    bfs(landList[i].first, landList[i].second);
  }

  cout << _max - 1 << '\n';
  return 0;
}
  