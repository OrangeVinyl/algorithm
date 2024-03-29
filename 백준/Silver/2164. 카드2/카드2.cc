#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, tmp;
queue<int> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  while(q.size() > 1) {
    q.pop();
    tmp = q.front();
    q.pop();
    q.push(tmp);
  }

  tmp = q.front();

  cout << tmp;

  return 0;
}
