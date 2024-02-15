#include <bits/stdc++.h>
using namespace std;

int tc, cnt;
string name, type;

int main() {
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> cnt;
    unordered_map<string, int> clothes;
    int ret = 1;

    for (int j = 0; j < cnt; j++) {
      cin >> name >> type;
      clothes[type]++;
    }

    for (auto it : clothes) {
        // 해당 영역 안입는 경우도 포함
        ret *= it.second + 1;
    }

    // 모든 경우 - 하나도 안입는 경우
     cout << ret - 1 << '\n';
  }
  return 0;
}