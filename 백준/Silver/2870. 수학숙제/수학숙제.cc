#include <bits/stdc++.h>
using namespace std;

/*
    숫자 찾기 , 비내림차순(오름차순)
    숫자 앞에 0이 있는 경우 정리 가능
*/

int n;
string s;
vector<string> ret;

void checkNumber(string s) {
  string temp = "";
  for (int j = 0; j < s.size(); j++) {
    // ASCII 코드 65 이하에 숫자가 있음
    if (s[j] < 65)
      temp += s[j];
    else if (temp.size()) {
      while (true) {
        if (temp.size() && temp.front() == '0')
          temp.erase(temp.begin());
        else
          break;
      }
      // 예시) 0000 인 경우
      if (temp.size() == 0) temp = "0";

      ret.push_back(temp);
      temp = "";
    }
  }
  if (temp.size()) {
    while (true) {
        if(temp.size() && temp.front() == '0') temp.erase(temp.begin());
        else break;
    }

    if (temp.size() == 0) temp = "0";
    ret.push_back(temp);
  }
}

// 문자열은 ASCII 코드 기준으로 계산되기 때문에 커스텀 함수가 필요하다.
bool cmp(string a, string b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    checkNumber(s);
  }

  sort(ret.begin(), ret.end(), cmp);

  for (string r : ret) {
    cout << r << '\n';
  }
}
