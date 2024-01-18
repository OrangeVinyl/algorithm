#include <bits/stdc++.h>
using namespace std;

/**
 * @brief n진법 변환
 * ex) 10진법을 2진법으로 변환하는 코드
 * b를 3으로 변경 시, 10진법을 3진법으로 바꾸는 방법이 된다.
 */

vector<int> v;

int main() {
  int n = 100;
  int b = 2;
  while (n > 1) {
    v.push_back(n % b);
    n /= b;
  }

  if (n == 1) {
    v.psuh_back(1);
  }

  reverse(v.begin(), v.end());

  for (int a : v) {
    if (a >= 10) cout << char(a+55);
    else cout << a;
  }
  
  return 0;
}
