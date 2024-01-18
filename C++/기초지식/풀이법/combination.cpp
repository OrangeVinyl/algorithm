#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 재귀를 이용한 조합
 * @brief combi()는 외우도록 하자
 */

int n = 5, k = 3, a[5] = {1, 2, 3, 3, 5};

void print(vector<int> b) {
  for (int i : b) cout << i << ' ';
  cout << '\n';
}

void combi(int start, vector<int> b) {
  if (b.size() == k) {
    print(b);
  }

  for (int i = start + 1; i < n; i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
  return;
}

int main() {
  vector<int> b;
  combi(-1, b);
  return 0;
}

/**
 * @brief 중첩 for문을 이용한 조합
 *
 */

void secondCombi() {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        cout << i << ' ' << j << ' ' << k << '\n';
      }
    }
  }
}

void anotherCase() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; i++) {
        cout << i << ' ' << j << ' ' << k << '\n';
      }
    }
  }
}