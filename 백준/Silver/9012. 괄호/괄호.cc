#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int tc;
string s;

vector<string> ret;

int main() {
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cin >> s;
    stack<char> stk;
    bool flag = true;

    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        stk.push(s[j]);
      } else {
        if (!stk.empty()) {
          stk.pop();
        } else {
          flag = false;
          break;
        }
      }
    }

    if (!stk.empty()) flag = false;

    if (flag == true) {
      ret.push_back("YES");
    } else {
      ret.push_back("NO");
    }
  }

  for (string c : ret) {
    cout << c << '\n';
  }

  return 0;
}