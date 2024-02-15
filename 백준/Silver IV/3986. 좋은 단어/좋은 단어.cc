#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    stack<char> stk;

    for(char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    if (stk.empty()) cnt++;
  }

  cout << cnt;

  return 0;
}