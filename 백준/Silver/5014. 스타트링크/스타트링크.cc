#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000005

int f, s, g, u, d;
int dist[MAX];
bool visited[MAX];

int bfs() {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  dist[s] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (x == g) return dist[x];

    // 위로 이동
    int nx_up = x + u;
    if (nx_up <= f && !visited[nx_up]) {
      visited[nx_up] = true;
      dist[nx_up] = dist[x] + 1;
      q.push(nx_up);
    }

    // 아래로 이동
    int nx_down = x - d;
    if (nx_down >= 1 && !visited[nx_down]) {
      visited[nx_down] = true;
      dist[nx_down] = dist[x] + 1;
      q.push(nx_down);
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> f >> s >> g >> u >> d;

  memset(dist, -1, sizeof(dist));
  memset(visited, false, sizeof(visited));

  int result = bfs();

  if (result == -1) {
    cout << "use the stairs";
  } else {
    cout << result;
  }
}