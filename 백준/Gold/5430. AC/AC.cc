#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int t, n;
string rule, str_n;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  cin >> t;

  while (t--) {
    cin >> rule;
    cin >> n;
    cin >> str_n;

    deque<int> dq;
    bool flag = true; // error
    bool dir = true; // 정방향 | 역방향
    /* 2자리 이상 일 수 있기 때문 */
    string tmp = "";


    for (int i = 1; i < str_n.size(); i++) {
      if (str_n[i] == ',' || str_n[i] == ']') {
        if ( tmp != "") {
          dq.push_back(stoi(tmp));
          tmp = "";
        }
      } else {
        tmp += str_n[i];
      }
    }

    for (int i = 0; i < rule.size(); i++) {
      if(rule[i] == 'R') {
        dir = !dir;
      } else if (rule[i] == 'D') {
        if (dq.empty()) {
          flag = false;
          break;
        } else {
          if (dir) {
            dq.pop_front();
          } else {
            dq.pop_back();
          }
        }
      }
    }

    if (!flag) {
      cout << "error\n";
    } else {
      if (!dir) {
        reverse(dq.begin(), dq.end());
      }

      cout << '[';

      for (int i = 0; i < dq.size(); i++) {
        if (i == dq.size() - 1) {
          cout << dq[i];
        } else {
          cout << dq[i] << ",";
        }
      }
      cout << "]\n";
    }
  }
}
