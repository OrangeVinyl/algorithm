#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> graph, int target, int idx, int val) {
    if (idx == graph.size()) {
        if (target == val) answer++;
        return;
    }
    dfs(graph, target, idx + 1, val - graph[idx]);
    dfs(graph, target, idx + 1, val + graph[idx]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}