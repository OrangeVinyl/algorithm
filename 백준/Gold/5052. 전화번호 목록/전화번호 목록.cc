#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    int n;
    string s;
    bool flag = true;
    vector<string> n_list;

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      n_list.push_back(s);
    }

    sort(n_list.begin(), n_list.end());

    for (int k = 0; k < n_list.size() - 1; k++) {
      string cur = n_list[k];
      string next = n_list[k + 1];

      if (cur.length() > next.length()) continue;
      if (cur == next.substr(0, cur.length())) {
        flag = false;
        break;
      }
    }

    if (!flag)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
