#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a = -1, b = -1, c = -1;

bool calc(int a, int b, int c) { return c * c == a * a + b * b; }

string check(int a, int b, int c) {
  if (calc(a, b, c))
    return "right";
  else
    return "wrong";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    cin >> a >> b >> c;
    int tmp = 0;

    if (a == 0 && b == 0 && c == 0) break;

    if (a > b) {
      tmp = b;
      b = a;
      a = tmp;
    }

    if (b > c) {
      tmp = c;
      c = b;
      b = tmp;
    }

    cout << check(a, b, c) << '\n';
  }

  return 0;
}