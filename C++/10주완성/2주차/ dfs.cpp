#include <bits/stdc++.h>
using namespace std;

const int n = 6;
int visited[n];
vector<int> adj[n];

void dfs(int start) {
    visited[start] = true;
    for (int v: adj[start]) {
        if (visited[v] == true) {
            dfs(v);
        }
    }
    return;
}

void main() {
     adj[1].push_back(2); 
     adj[1].push_back(3); 
     adj[2].push_back(4); 
     adj[4].push_back(2); 
     adj[2].push_back(5); 
     dfs(1);
}