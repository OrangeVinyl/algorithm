#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;
bool visited[10001];
bool isAnswer;
int cnt = 1;

void dfs(string curr, vector<vector<string>> tickets) {
    answer.push_back(curr);
    
    // 기저 조건 - answer 배열이 tickets배열과 길이가 같은 경우
    if (cnt == (int)tickets.size()) {
        isAnswer = true;
    }
        
    // 조건문
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == curr) {
            visited[i] = true;
            cnt++;
            dfs(tickets[i][1], tickets);
            
            // backTracking - 정답이 아닌 경우 방문처리 취소 및 Answer에서 제외
            if (!isAnswer) {
                answer.pop_back();
                visited[i] = false;
                cnt--;
            }
        }
        
    }
        
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets);
    
    return answer;
}
