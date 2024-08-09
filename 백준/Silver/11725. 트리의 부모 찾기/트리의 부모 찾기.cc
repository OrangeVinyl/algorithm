#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int n;
int res[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int k) {
    visited[k] = true;
    for (int i = 0; i < v[k].size(); i++) {
        int next = v[k][i];
        if (!visited[next]) {
            res[next] = k;
            dfs(next);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) cout << res[i] << '\n';

    return 0;
}
