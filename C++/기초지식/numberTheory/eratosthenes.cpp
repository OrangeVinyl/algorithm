#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 에라토스테네스의 체
 * 소수가 아닌 값들에 대한 불리언 배열을 만들어 소수만을 걸러낼 수 있는 방법
 * 시간복잡도: O(Nlog(logn))
 */

const int max_n = 40;
bool che[max_n + 1];

vector<int> era(int mx_n) {
  vector<int> v;
  // 소수판별기능이므로 2부터
  for (int i = 2; i <= mx_n; i++) {
    if (che[i]) continue;
    for (int j = 2 * i; j < mx_n; j += i) {
      che[j] = 1;
    }
  }
  for (int i = 2; i <= mx_n; i++)
    if (che[i] == 0) v.push_back(i);
  return v;
}

int main() {
  vector<int> a = era(max_n);
  for (int i : a) cout << i << ' ';
}

/**
 * @brief
 * 위의 코드는 배열의 크기가 필요하기 때문에 배열의 크기가 일정 수준(1000만
 * 이상)을 벗어나면 쓰기가 힘들다. 이럴 때는 일일히 소수를 판별하는 bool 함수를
 * 만들어줘야 한다.
 */

bool check(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main2() {
  for (int i = 1; i <= 20; i++) {
    if (check(i)) {
      cout << i << '는 소수입니다\n';
    }
  }
  return 0;
}