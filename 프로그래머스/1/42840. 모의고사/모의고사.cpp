#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int p1[5] = {1, 2, 3, 4, 5};
int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int cnt[3] = {0,0,0};
int max_num;
vector<int> answer;

vector<int> solution(vector<int> answers) {
    for (int i = 0; i < answers.size(); i++) {
        if (p1[i % 5] == answers[i]) cnt[0]++;
        if (p2[i % 8] == answers[i]) cnt[1]++;
        if (p3[i % 10] == answers[i]) cnt[2]++;
    }
    
    for (int i = 0; i < 3; i++) {
        max_num = max(max_num, cnt[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        if (max_num == cnt[i]) answer.push_back(i+1);
    }
    
    return answer;
}