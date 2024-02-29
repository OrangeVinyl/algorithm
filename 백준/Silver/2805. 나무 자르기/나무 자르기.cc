#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long n, m, ret;
vector<long long> v;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  // 톱날 길이의 최대 | 최소
  long long lo = 0;
  long long hi = 1000000000;

  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] - mid > 0) {
        sum += v[i] - mid;
      }
    }

    if (sum >= m) {  // m 미터보다 가져간 나무가 같거나 많으면
      ret = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  cout << ret;

  return 0;
}