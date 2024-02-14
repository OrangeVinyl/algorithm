#include <bits/stdc++.h>
using namespace std;

int cnt;
string pattern, pre, suf, t;

int main() {
  cin >> cnt;
  cin >> pattern;

  int pos = pattern.find('*');
  pre = pattern.substr(0, pos);
  suf = pattern.substr(pos + 1);

  for (int i = 0; i < cnt; i++) {
    cin >> t;
    if (pre.size() + suf.size() > t.size()) {
      cout << "NE\n";
    } else {
      if (pre == t.substr(0, pre.size()) &&
          suf == t.substr(t.size() - suf.size())) {
        cout << "DA\n";
      } else
        cout << "NE\n";
    }
  }
  return 0;
}