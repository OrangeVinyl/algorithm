#include <iostream>
#include <vector>

using namespace std;

int res, t, n, x, y;
int a[104][104] = {0}, visited[104] = {0};

void dfs(int s) {
  res++;
  visited[s] = 1;

  for (int i = 1; i <= t; i++) {
    if (a[s][i] && !visited[i]) {
      dfs(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }

  dfs(1);

  cout << res - 1 << '\n';

  return 0;
}