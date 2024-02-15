#include <bits/stdc++.h>
using namespace std;

int a[15001];
int n, m, ret;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> m;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (a[i] + a[j] == m) ret++;
    }
  }

  cout << ret;

  return 0;
}