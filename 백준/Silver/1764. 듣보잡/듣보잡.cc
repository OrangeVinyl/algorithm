#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<string> a, ans;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < m; i++) {
    cin >> s;
    if (binary_search(a.begin(), a.end(), s)) {
      ans.push_back(s);
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (auto o : ans) {
    cout << o << '\n';
  }
}
