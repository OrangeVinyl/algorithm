#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, res = -987654321;
string s;
vector<int> num;
vector<char> oper_arr;

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int oper(char a, int b, int c) {
  if (a == '+') return b + c;
  if (a == '-') return b - c;
  if (a == '*') return b * c;
}

// here: idx _sum : 총합
void solve(int here, int _sum) {
  if (here == num.size() - 1) {
    res = max(res, _sum);
    return;
  }

    // 괄호를 묶지 않는 경우
  solve(here + 1, oper(oper_arr[here], _sum, num[here + 1]));

  // 괄호를 묶는 경우
  if (here + 2 <= num.size() - 1) {
    int temp = oper(oper_arr[here + 1], num[here + 1], num[here + 2]);
    solve(here + 2, oper(oper_arr[here], _sum, temp));
  }
}

int main(void) {
  fastIO();

  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      num.push_back(s[i] - '0');
    } else {
      oper_arr.push_back(s[i]);
    }
  }

  solve(0, num[0]);

  cout << res;

  return 0;
}