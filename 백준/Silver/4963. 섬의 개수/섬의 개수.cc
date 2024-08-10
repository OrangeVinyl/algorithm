#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w, h;
int m[50][50];
int v[50][50];
int res;

int dy[8] = {1,1,0,-1,-1,-1,0,1}, dx[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;

        if (!v[ny][nx] && m[ny][nx]) {
            v[ny][nx] = 1;
            dfs(ny,nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        // 초기화
        memset(m, 0, sizeof(m));
        memset(v, 0, sizeof(v));
        res = 0;

        // 입력
        for(int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> m[i][j];
            }
        }

        // 찾기
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // 땅이고 방문하지 않은 경우
                if (m[i][j] && !v[i][j]) {
                    v[i][j] = 1;
                    dfs(i,j);
                    res++;
                }
            }
        }

        cout << res << '\n';
    }



    return 0;
}


