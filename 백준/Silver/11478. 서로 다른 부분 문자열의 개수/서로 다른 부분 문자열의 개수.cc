#include <iostream>
#include <stack>
#include <set>

using namespace std;

string s;
set<string> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    string tmp;
    char start_word = s[i];
    tmp += s[i];
    
    a.insert(tmp);

    for (int j = i + 1; j < s.size(); j++) {
      tmp += s[j];
      a.insert(tmp);
    }
  }

  cout << a.size();
}