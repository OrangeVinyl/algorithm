#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n, m, a[104][104], ret, cheese_cnt, cnt, melted_cnt;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool visited[104][104];

void bfs() {
  queue<pair<int,int>> q;
  q.push({0,0});

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (visited[ny][nx]) continue;

      if (a[ny][nx] == 0) {
        q.push({ny,nx});
      } else {
        cnt++;
        a[ny][nx] = 0;
      }

      visited[ny][nx] = true;
    }
  }

  melted_cnt += cnt;
}

int main() {
  cin >> n >> m;

  for (int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cheese_cnt++;
    }
  }

  while(true) {
    memset(visited, false, sizeof(visited));
    cnt = 0;
    
    bfs();
    if (cheese_cnt == melted_cnt) break;
    ret++;
  }

  cout << ret + 1 << '\n';
  cout << cnt;
}
