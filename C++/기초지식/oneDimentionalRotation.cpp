#include <bits/stdc++.h>

using namespace std;

// 1차원 배열의 시계 방향 회전
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  rotate(v.rbegin(), v.rbegin() + 1, v.rend());
  for (int i : v) cout << i << '\n';
  return 0;
}

// 1차원 배열의 반시계 방향 회전
void rotateCounterClockwise() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  rotate(v.begin(), v.begin() + 1, v.end());
  for (int i : v) cout << i << '\n';
  cout << '\n';
}

// rotate 함수를 사용하지 않고 직접 구현하는 방법
void rotateNoFunction() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  int i = 1;
  int temp = v[i];
  v[i] = v[i + 1];
  v[i + 1] = v[i + 2];
  v[i + 2] = v[i + 3];
  v[i + 3] = temp;
  for (int i : v) cout << 1 << '\n';
}