#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string s;

vector<string> ret;

int main() {
  while(true) {
    getline(cin,s);
    if (s == ".") break;
    stack<char> stk;
    bool flag = true;

    for (int j = 0; j < s.size(); j++) {
      
      if (s[j] == '(' || s[j] == '[') {
        stk.push(s[j]);
      } else if (s[j] == ')') {
        if (!stk.empty() && stk.top() == '(') {
          stk.pop();
        } else {
          flag = false;
          break;
        }
      } else if (s[j] == ']') {
        if (!stk.empty() && stk.top() == '[') {
          stk.pop();
        } else {
          flag = false;
          break;
        }
      }
    }

    if (!stk.empty()) flag = false;

    if (flag == true) {
      ret.push_back("yes");
    } else {
      ret.push_back("no");
    }
  }

  for (string c : ret) {
    cout << c << '\n';
  }

  return 0;
}