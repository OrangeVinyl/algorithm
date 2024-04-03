#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, dp[1000001];


int solve(int a) {

}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  // bottom - up 방식

  // dp 배열에 인덱스에 맞는 수 할당
  for (int i = 1; i <= n; i++) {
    dp[i] = i;
  }

  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2]);
    if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3]);
    dp[i] = min(dp[i], dp[i-1]) + 1; // if 문으로 걸러줬기 때문에 dp[i] 에는 이전 로직에 횟수가 +1 되어야 한다.
  }

  cout << dp[n]-1  << '\n';

  while(n != 0) {
    cout << n << ' ';

    if (dp[n] == dp[n-1] + 1) {
      n -= 1;
    } else if (n % 2 == 0 && dp[n] == dp[n/2] + 1) {
      n /= 2;
    } else if (n % 3 == 0 && dp[n] == dp[n/3] + 1) {
      n /= 3;
    }
  }

  return 0;
}