#include <bits/stdc++.h>
using namespace std;

int n, m, maps[54][54], result = 9999999;
vector<pair<int,int>> ck, h;
vector<vector<int>> combiCk;

// ck의 인덱스만 저장
void combi(int start, vector<int> v) {
  if (v.size() == m) {
    combiCk.push_back(v);
    return;
  }
  
  for (int i = start + 1; i < ck.size(); i++) {
    v.push_back(i);
    combi(i,v);
    v.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maps[i][j];

      if (maps[i][j] == 1) h.push_back({i,j});
      if (maps[i][j] == 2) ck.push_back({i,j});
    }
  }

  // 살릴 치킨집을 고르기 
  vector<int> v;
  combi(-1, v);

  // 도시의 치킨거리 최솟값 구하기
  for (vector<int> clist : combiCk) {
    int ret = 0;

    for(pair<int,int> home : h) {
      int __min = 9999999;

      for(int c : clist) {
        int __dist = abs(home.first - ck[c].first) + abs(home.second - ck[c].second);
        __min = min(__min, __dist);
      }
      ret += __min;
    }
    result = min(result, ret);
  }
  cout << result << '\n';
  return 0;
}