#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, tmp;
queue<int> q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  cout << '<';

  while(q.size() > 1) {
    for(int i = 0; i < k-1; i++) {
      tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    tmp = q.front();
    cout << tmp << ", ";
    q.pop();
  }

  tmp = q.front();


  cout << tmp << ">\n";

  return 0;
}