#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;

int com(int a, int b) {
  if (a == b || b == 0) return 1;
  else return com(a-1, b-1) + com(a-1,b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  cout << com (n,k);

  return 0;
}

