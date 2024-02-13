/*
    - 한번 쓴 단어는 다시 쓰지 않는다.
    - target 문자열과 동일하게 변환이 완료되어 재귀함수가 종료되었을 경우,
      다른 최소 경로의 변환과정이 있을 수 있기 때문에 해당 탐색 과정에서 다시 가장 가까운 
      길로 돌아와서 다른 방향으로 탐색을 이어나가야 한다.(back-tracking)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;
bool visited[51];

bool check_diff(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) cnt++; 
    }
    if (cnt == 1) return true;
    return false;
}

void dfs(string curr_word, string target, vector<string> words, int step) {
    if (curr_word == target) {
        answer = min(answer, step);
        return;
    };
    
    for (int i = 0; i < words.size(); ++i) {
        if (!visited[i] && check_diff(words[i], curr_word)) {
            visited[i] = true;
            dfs(words[i], target, words, step + 1);
            // 재귀함수가 끝난 경우, 즉 target과 일치하지 않은 경우 방문처리 취소(back-tracking) 
            // 다른 방향으로 다시 탐색
            visited[i] = false;
        }
    }
    
    return;
}



int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    
    // 변환할 수 없는 경우에는 0를 return 합니다.
    if (answer == 50) return 0;
    
    return answer;
}