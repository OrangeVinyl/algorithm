#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, ret;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // init
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int val;
    cin >> val;
    v.push_back(val);
  }

  int lo = 1;
  int hi = 1000000001;  // 최대보다 조금 더 큰 수

  // 이진탐색 시작
  while (lo <= hi) {
    int mid = (lo + hi) / 2;  // 한 사람이 받을 수 있는 보석의 최대 OR 최소 갯수
    ll cnt = 0;

    for (int i = 0; i < m; i++) {
      cnt += v[i] / mid;
      if (v[i] % mid) cnt++;  // 나누어 떨어지지 않으면 한 사람 추가
    }

    if (cnt <= n) {
      // cnt가 현재 인원 수 보다 작으면 정답
      ret = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }

  cout << ret;
  return 0;
}
