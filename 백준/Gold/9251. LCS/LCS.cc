#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string string_a, string_b;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> string_a;
  cin >> string_b;

  int a_leng = string_a.size() + 1;
  int b_leng = string_b.size() + 1;

  int lcs[a_leng + 4][b_leng + 4];

  memset(lcs, 0, sizeof(lcs));

  for (int i = 0; i < a_leng; i++) {
    for (int j = 0; j < b_leng; j++) {
      if (i == 0 || j == 0) {
        lcs[i][j] = 0;
      } else if (string_a[i - 1] == string_b[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      } else {
        lcs[i][j] = max(lcs[i -1][j], lcs[i][j - 1]);
      }
    }
  }

  cout << lcs[a_leng -1][b_leng - 1];
}