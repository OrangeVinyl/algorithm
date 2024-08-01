#include <iostream>
#include <queue>

using namespace std;

int n, k, res;

int a[100001];

void bfs(int x) {
  queue<int> q;
  q.push(x);

  while (!q.empty()) {
    int dx = q.front();
    q.pop();

    if (dx < 0 || dx > 100000) continue;

    if (dx == k) {
      cout << a[dx];
      break;
    }

    if (dx - 1 >= 0 && a[dx -1] == 0) {
      a[dx - 1] = a[dx] + 1;
      q.push(dx - 1);
    }

    if (dx + 1 <= 100000 && a[dx + 1] == 0) {
      a[dx + 1] = a[dx] + 1;
      q.push(dx + 1);
    }

    if (dx * 2 <= 100000 && a[dx*2] == 0) {
      a[dx * 2] = a[dx] + 1;
      q.push(dx*2);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  bfs(n);
}