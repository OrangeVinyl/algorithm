#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n, sum(-1), mx(-1);
int a[103];

//  3 <= n =<100
// 그 다음 줄에서는 100,000을 넘지 않는 수
// 10 <= m <= 300000
// 넘지 않으면서 -> 같거나 작은

int main(void) {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        sum = a[i] + a[j] + a[k];
        if (mx < sum && sum  <= m)  mx = sum;
      }
    }
  }

  cout << mx;

  return 0;
}
