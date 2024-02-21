#include <bits/stdc++.h>
using namespace std;

int h, w;
int jo1[101][101];
string s;

int main() {
  memset(jo1, -1, sizeof(jo1));

  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == 'c') jo1[i][j] = 0;
      if (s[j] == '.') continue;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (jo1[i][j] == 0 && jo1[i][j + 1] != 0)
        jo1[i][j + 1] = jo1[i][j] + 1;
      else if (jo1[i][j] == -1 && jo1[i][j] == -1) continue;
      else if (jo1[i][j] != 0 && jo1[i][j+1] != 0) 
        jo1[i][j+1] = jo1[i][j] + 1;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << jo1[i][j] << ' ';
    }
    cout << '\n';
  }
}