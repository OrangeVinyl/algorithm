#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, erase_n, root, cnt;
vector<int> a[51];

int dfs(int curr_n) {
  if (curr_n == erase_n) return -1;
  if (!a[curr_n].size()) {
    cnt++;
    return 0;
  } 

  for (int i = 0 ; i < a[curr_n].size(); i++) {
    int temp = dfs(a[curr_n][i]);
    if (temp == - 1 && a[curr_n].size() == 1) {
      cnt++;
    }
  }
  return 0;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int parent = 0;
    cin >> parent;
 
    if (parent == -1) root = i;
    else a[parent].push_back(i);
  }

  cin >> erase_n;

  dfs(root);
  cout << cnt;
}
