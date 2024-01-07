#include <bits/stdc++.h>
using namespace std;

/**
 * @brief permuatation
 * 순열을 사용할 때 정렬이 되어 있지 않은 경우, sort() 함수를 통해 정렬 후 진행
 */

int main() {
  int a[] = {1, 2, 3};
  do {
    for (int i : a) cout << i << " ";
    cout << '\n';
  } while (next_permutation(a, a + 3));

  return 0;
}

int secondWay() {
  int a[] = {1, 2, 3};
  do {
    for (int i : a) cout << i << " ";
    cout << '\n';
  } while (next_permutation(&a[0], &a[0] + 3));
}

int ifVector() {
  vector<int> a = {1, 2, 3};
  do {
    for (int i : a) cout << i << ' ';
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}

int ifNotSorted() {
  vector<int> a = {2, 1, 3};
  sort(a.begin(), a.end());
  do {
    for (int i : a) cout << i << '';
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}

// 5개 중 2개를 뽑는 경우, slice 해서 뽑는 경우가 있다.

int example {
  vector<int> a = {2, 1, 3};
  sort(a.begin(), a.end());
  do {
    for (int i = 0; i < 2; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}