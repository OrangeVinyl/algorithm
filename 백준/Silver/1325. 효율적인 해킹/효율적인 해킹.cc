#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, max_cnt, dp[10004];
vector<int> adj[10004];
bool visited[10004];

int dfs(int here) {
  visited[here] = true;
  int ret = 1;  // 현재 노드도 카운팅에 포함

  for (int next : adj[here]) {
    if (!visited[next]) {
      ret += dfs(next);
    }
  }
  return ret;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    memset(visited, false, sizeof(visited));
    dp[i] = dfs(i);
    max_cnt = max(dp[i], max_cnt);
  }

  for (int i = 1; i <= n; ++i) {
    if (dp[i] == max_cnt) cout << i << ' ';
  }
}