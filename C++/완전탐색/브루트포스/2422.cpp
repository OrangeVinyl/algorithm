#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
bool notCombi[201][201];
vector<int> ret;

void combi(int size, int start) {
    if (size == 3) {
        for (int i : ret) {
            cout << i << ' ';
        }
        cout << '\n';

        // 가장 먼저 들어간 것을 기준으로 체킹
        if (notCombi[ret[0]][ret[1]] || notCombi[ret[0]][ret[2]]) return;
        cnt++;
        return;
    }

    for (int i = start; i <= n; i++) {
        if (notCombi[start][i] || start == i) continue;
        ret.push_back(i);
        combi (size + 1, i);
        ret.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // 맛이 없는 아이스크림 조합 구하기
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        notCombi[from][to] = true;
        notCombi[to][from] = true;
    }

    combi(0,0);
    cout << cnt;

    return 0;
}