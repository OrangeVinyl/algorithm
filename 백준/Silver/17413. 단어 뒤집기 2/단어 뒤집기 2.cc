#include <iostream>
#include <stack>

using namespace std;

string s, res;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, s);
  stack<char> reversed_word;
  bool flag = false;

  for (int i = 0; i < s.size(); i++) {
    if (flag) {
      if (s[i] == '>') {
        res += s[i];
        flag = false;
        continue;
      }
      res += s[i];
    }

    if (s[i] == '<') {
      res += s[i];
      flag = !flag;
    } else {
      if (flag) continue;
      reversed_word.push(s[i]);

      if (s[i] == ' ') {
        reversed_word.pop();

        while (!reversed_word.empty()) {
          res += reversed_word.top();
          reversed_word.pop();
        }

        res += ' ';
      }

      if (s[i + 1] == '<') {
        while (!reversed_word.empty()) {
          res += reversed_word.top();
          reversed_word.pop();
        }
      }
    }
  }

  while (!reversed_word.empty()) {
    res += reversed_word.top();
    reversed_word.pop();
  }

  cout << res;
}
