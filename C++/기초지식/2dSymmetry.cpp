#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 2차원 배열 대칭
 *
 * 1 2 3     1 4 7
 * 4 5 6 ->  2 5 8
 * 7 8 9     3 6 9
 *
 */

int main() {
  vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int b[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b[j][i] = v[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
