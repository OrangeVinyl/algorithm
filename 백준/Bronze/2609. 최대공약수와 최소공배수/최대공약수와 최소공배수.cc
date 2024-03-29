#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
queue<int> q;

// * 최대 공약수
int gcd(int a, int b) {
  int c = a % b;

  while(c != 0) {
    a = b;
    b = c;
    c = a % b;
  }

  return b;
}

/**
 * * 최대공약수 * 최소공배수 = 두 수의 곱
 */

int lcm (int a, int b) {
  return (a*b) / gcd(a,b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  cout << gcd(n,m) << '\n' << lcm(n,m);

  return 0;
}