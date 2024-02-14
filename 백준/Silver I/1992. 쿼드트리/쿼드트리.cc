#include <bits/stdc++.h>

using namespace std;

int n;
char maps[65][65];

// 재귀 & 분할 정복
string quard(int y, int x, int size) {
    // 최대한 쪼갠 경우
    if (size == 1) return string(1,maps[y][x]);

    char target = maps[y][x];
    string answer = "";

    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if (target != maps[i][j]) {
                answer += '(';

                // 왼쪽 위
                answer += quard(y, x, size/2);
                // 오른쪽 위
                answer += quard(y, x + size/2, size/2);
                // 왼쪽 아래
                answer += quard(y + size/2, x, size/2);
                // 오른쪽 아래
                answer += quard(y + size/2, x + size/2, size/2);

                answer += ')';

                return answer;
            }
        }
    }

    // 영역 내 다른 것이 없는 경우
    return string(1, maps[y][x]);
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            maps[i][j] = s[j];
        }    
    }

    cout << quard(0, 0, n);

    return 0;
}