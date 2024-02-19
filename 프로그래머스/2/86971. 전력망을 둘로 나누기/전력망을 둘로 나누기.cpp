#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[101];
int graph[101][101];

int dfs(int curr, int n) {
    if (visited[curr]) return 0;
    
    // 노드를 카운트 할 변수
    int ret = 1;
    visited[curr] = true;
    
    for(int i = 1; i <= n; ++i) {
        // 연결되었지만 탐색하지 않은 경우
        if (graph[curr][i]) ret += dfs(i,n);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;    
    
    // 초기화 - 그래프 삽입
    for(int i = 0; i < wires.size(); ++i) {
        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;
    }
    
    // 하나씩 끊으면서 차이값 비교
    for(int i = 0; i < wires.size(); ++i) {
        // 그래프 간선 하나씩 끊기
        graph[wires[i][0]][wires[i][1]] = graph[wires[i][1]][wires[i][0]] = 0;
        memset(visited, false, sizeof(visited));
        vector<int> diff;
        
        for (int j = 1; j <= n; ++j) {
            int temp_cnt = dfs(j, n);
            
            if (temp_cnt == 0) continue;
            diff.push_back(temp_cnt);
        }
        
        answer = min(answer, abs(diff[0] - diff[1]));
        
        // 그래프 간선 다시 연결하기
        graph[wires[i][0]][wires[i][1]] = graph[wires[i][1]][wires[i][0]] = 1;                   
    }
    
    
    return answer;
}