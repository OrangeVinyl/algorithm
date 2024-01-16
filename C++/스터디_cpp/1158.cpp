// 백준 1158 | 요세푸스
#include <bits/stdc++.h>
using namespace std;

int N, K, p;
queue<int> q;

int main(void) {
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    q.push(i);
  }
  cout << "<";

  do {
    for (int i = 1; i < K; i++) {
      int a = q.front();
      q.pop();
      q.push(a);
    }
    p = q.front();
    q.pop();
    cout << p << ", ";
  } while (q.size() != 1);

  cout << q.front() << ">"
       << "\n";

  return 0;
}