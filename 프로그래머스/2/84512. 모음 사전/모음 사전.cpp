#include <string>
#include <vector>
#include <set>

using namespace std;

char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
set<string> words;

void dfs(string s) {
    if (s.length() == 5) return;
    
    for (int i = 0; i < 5; ++i) {
        dfs(s + alpha[i]);
        words.insert(s + alpha[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    // dfs를 통해 모든 값 탐색
    dfs("");
    
    // 순회를 하며 일치하는 값 탐색
    for (string x : words) {
        answer++;
        
        if (word == x) break;
    }
    
    return answer;
}