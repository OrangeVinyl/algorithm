#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, k, ret;
ll max_l;
vector<ll> v;

int main() {
  cin >> k >> n;

  for (int i = 0; i < k; i++) {
    ll tmp;
    cin >> tmp;
    max_l = max(max_l, tmp);
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  ll lo = 1;
  ll hi = max_l;

  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    ll cnt = 0;

    for (ll i : v) {
      cnt += i / mid;
    }

    if (cnt >= n) {
      ret = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ret;

  return 0;
}
