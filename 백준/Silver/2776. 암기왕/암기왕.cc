#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int tc, n, m;
vector<int> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> tc;
  while(tc--) {
    // 반복진행 시, 초기화
    a.clear();
    b.clear();
    
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cin >> m;
    b.resize(m);

    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

    // 이분탐색을 위한 정렬
    sort(a.begin(), a.end());

    for (int k = 0; k < m; k++) {
      if (binary_search(a.begin(), a.end(), b[k]))
        cout << "1"
             << "\n";
      else
        cout << "0"
             << "\n";
    }
  }
}