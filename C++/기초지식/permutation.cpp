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

void secondWay() {
  int a[] = {1, 2, 3};
  do {
    for (int i : a) cout << i << " ";
    cout << '\n';
  } while (next_permutation(&a[0], &a[0] + 3));
}

void ifVector() {
  vector<int> a = {1, 2, 3};
  do {
    for (int i : a) cout << i << ' ';
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}

void ifNotSorted() {
  vector<int> a = {2, 1, 3};
  sort(a.begin(), a.end());
  do {
    for (int i : a) cout << i << '';
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}

// 5개 중 2개를 뽑는 경우, slice 해서 뽑는 경우가 있다.

void example {
  vector<int> a = {2, 1, 3};
  sort(a.begin(), a.end());
  do {
    for (int i = 0; i < 2; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  } while (next_permutation(a.begin(), a.end()));
}


/**
 * @brief 재귀함수로 만드는 순열
 * 굳이 외울 필요는 없지만 알아서 나쁠 건 없다.
 * 
 * @param n 
 * @param r 
 * @param depth 
 */
void makePermutation (int n, int r, int depth) {
  cout << n << ' : ' << r << ' : ' << depth << '\n';
  if ( r === depth) {
    printV(v)
    return;
  }

  for (int i = depth; i < n; i++) {
    swap (v[i], v[depth])
    makePermutation(n,r,depth + 1)
    swap (v[i], v[depth])
  }



}