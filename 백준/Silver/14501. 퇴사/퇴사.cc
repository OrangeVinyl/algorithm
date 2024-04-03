#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[16], Ti[16], Pi[16];
int max_m;

void solve(int day, int sum) {
  if (day > n) return;

  max_m = max(max_m, sum);

  for (int i = day; i < n; i++) {
    solve(Ti[i] + i, Pi[i] + sum);
  }
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> Ti[i] >> Pi[i];
  }

  solve(0,0);

  cout << max_m;

  return 0;
}