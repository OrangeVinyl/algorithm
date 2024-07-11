#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, res = 0;
string n_str, m_str;
vector<string> a;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> n_str;
    a.push_back(n_str);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < m; i++) {
    cin >> m_str;
    if (binary_search(a.begin(), a.end(), m_str)) res++;
  }

  cout << res;
}