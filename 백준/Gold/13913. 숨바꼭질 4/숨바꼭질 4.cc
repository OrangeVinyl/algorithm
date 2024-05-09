#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define prev aaaaaaa

// prev에 담기는 값이 20만 인 경우를 생각
const int max_n = 200004;
// prev 배열) 현재 위치를 담는 배열
int n, k, ret, here, prev[max_n], a[max_n];
queue<int> q;
vector<int> v;

int main(int argc, char *argv[]) {
  cin >> n >> k;

  a[n] = 1;
  q.push(n);

  while (q.size()) {
    here = q.front();
    q.pop();

    if (here == k) {
      ret = a[k];
      break;
    }

    for (int next : {here - 1, here + 1, here * 2}) {
      // 벗어나는 경우
      if (max_n <= next || next < 0 || a[next]) continue;
      a[next] = a[here] + 1;

      // tracing
      prev[next] = here;
      q.push(next);
    }
  }

  for(int i = k; i != n ; i = prev[i]) {
    v.push_back(i);
  }
  // 첫번째 값은 들어가지 않음
  v.push_back(n);

  cout << ret - 1 << '\n';

  reverse(v.begin(), v.end());
  for (int i : v) {
    cout << i << ' ';
  }

  return 0;
}
