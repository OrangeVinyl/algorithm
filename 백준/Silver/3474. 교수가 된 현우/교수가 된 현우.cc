#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t, val;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> val;
    int ret2 = 0;
    int ret5 = 0;

    for (int j = 2; j <= val; j *= 2) {
      ret2 += val / j;
    }
    for (int j = 5; j <= val; j *= 5) {
      ret5 += val / j;
    }
    v.push_back(min(ret2, ret5));
  }

  for (int i : v) {
    cout << i << '\n';
  }

  return 0;
}