#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
const int MAX = 100000;

// 시간
int a[MAX+4];
// 방법의 수
int cnt[MAX+4];

int main(int argc, char *argv[]) {
  cin >> n >> k;

  a[n] = 1;
  cnt[n] = 1;

  queue<int> q;
  q.push(n); 

  while(!q.empty()) {
    int now = q.front();
    q.pop();

    // std:initializer_list
    for (int next : {now - 1, now + 1, now * 2}) {
      if ( 0 <= next && next <= MAX ) {
        if (!a[next]) {
          q.push(next);
          a[next] = a[now] + 1;

          cnt[next] += cnt[now];
          // 시간 = 최단거리인 경우
        } else if (a[next] == a[now] + 1) {
          cnt[next] += cnt[now];
        }
      }
    }
  }

  cout << a[k] - 1 << '\n';
  cout << cnt[k] << '\n';
  return 0;
}
