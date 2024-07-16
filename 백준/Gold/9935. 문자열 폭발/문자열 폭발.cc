#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

string s, bomb, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  stack<char> stk;

  cin >> s;
  cin >> bomb;

  for (int i = 0; i < s.size(); i++) {

    stk.push(s[i]);

    if (s[i] == bomb[bomb.length() - 1] && stk.size() >= bomb.size()) {
      // 폭발 문자열의 마지막 단어 && 스택 원소 갯수 폭발 문자열 갯수 이상일 경우
      string tmp;

      for(int j = 0; j < bomb.length(); j++) {
        tmp.push_back(stk.top());
        stk.pop();
      }

      // 뺀 문자열 뒤집기
      reverse(tmp.begin(), tmp.end());

      // 문자열 일치 확인
      if (tmp.compare(bomb) != 0) {
        for (int i = 0; i < tmp.length(); i++) stk.push(tmp[i]);
      }
    }
  }

  while(!stk.empty()) {
    res += stk.top();
    stk.pop();
  }

  reverse(res.begin(), res.end());

  if (res.empty()) cout << "FRULA";
  cout << res;
}
