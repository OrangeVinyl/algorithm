#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[8];
int answer;

void dfs(int blood, vector<vector<int>> dungeons,int cnt) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && blood - dungeons[i][0] >= 0) {
            visited[i] = true;
            dfs(blood - dungeons[i][1], dungeons, cnt + 1);
            // 백트래킹-- 
            visited[i] = false;
        }
    }
    answer = max(answer, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    memset(visited, false, sizeof(visited));
    dfs(k, dungeons, 0);
    return answer;
}