#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, l, r, a[54][54], visited[54][54], cnt, sum;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>> v;

void dfs(int y, int x, vector<pair<int,int>> &v) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >=n || nx >= n) continue;
    if (visited[ny][nx]) continue;
    if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r) {
      visited[ny][nx] = 1;
      v.push_back({ny, nx});
      sum += a[ny][nx];

      // 재귀
      dfs(ny, nx, v);
    }
    
  }
} 

int main() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  while(true) {
    // 반복문 해제 트리거
    bool flag = false;
    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
    
    // 모든 영역 순회
    for(int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j]) {
            // 방문 표시
            visited[i][j] = 1;
            // 연합칸 담는 벡터 초기화
            v.clear();
            v.push_back({i,j});
            // 연합의 인구수 초기화
            sum = a[i][j];
            
            dfs(i, j, v);

            // 연합이 성사되지 않은 경우
            if (v.size() == 1) continue;

            for (pair<int,int> p : v) {
              a[p.first][p.second] = sum / v.size();
              // 반복문 지속
              flag = true;
            }
        }
      }
    }
    if (!flag) break;
    // 날짜 증가
    cnt++;
  }

  cout << cnt;
  return 0; 
}