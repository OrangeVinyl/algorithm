#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector<int> a[300001];
vector<int> dist(300001, -1);
vector<int> res;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < a[cur].size(); i++) {
            int next = a[cur][i];
            if (dist[next] == -1) {  // 아직 방문하지 않은 도시
                dist[next] = dist[cur] + 1;
                q.push(next);
                if (dist[next] == k) {
                    res.push_back(next);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    bfs(x);

    if (!res.empty()) {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << '\n';
        }
    } else {
        cout << -1;
    }

    return 0;
}