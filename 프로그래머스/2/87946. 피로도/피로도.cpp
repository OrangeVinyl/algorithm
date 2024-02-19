#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

bool visited[8];
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> perm(dungeons.size());
    iota(perm.begin(), perm.end(), 0);  // 0부터 시작하는 순열 생성

    do {
        int cnt = 0, blood = k;
        
        for (int i : perm) {
            if (blood >= dungeons[i][0]) {
                blood -= dungeons[i][1];
                cnt++;
            } else break;
        }
        
        answer = max(answer, cnt);
    } while (next_permutation(perm.begin(), perm.end()));

    return answer;
}