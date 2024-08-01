#include <iostream>
#include <vector>

using namespace std;

int n,m,cnt;
vector<int> a[1001];
bool visited[1001];

void dfs(int x) {
  visited[x] = true;

  for (int i = 0; i < a[x].size(); i++) {
    if (visited[a[x][i]]) continue;
    dfs(a[x][i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;


  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    dfs(i);
    cnt++;
  }

  cout << cnt;
}