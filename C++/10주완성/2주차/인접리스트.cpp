#include <bits/stdc++.h>
using namespace std;

// 정점은 0부터 9번까지 10개 노드 존재
// 1-2 / 1-3 / 3-4 경로 존재

const int v = 10;
vector<int> adj[v];
int visited[v];

void go(int idx) {
    cout << idx << '\n';
    visited[idx] = 1;
    for (int there: adj[idx]) {
        if (visited[there]) continue;
        go(there);
    }
}

void main() {
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    if (adj[i].size() && visitied[i] == 0) go(i);
}