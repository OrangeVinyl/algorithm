// 백준 2979번 | 트럭 주차
#include <bits/stdc++.h>
using namespace std;

int A, B, C, a, b, cnt[104], ret;
int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) {
            cnt[j] += 1;
        }
    }

    for (int k = 1; k < 100; k++) {
        if (cnt[k]) {
            if(cnt[k] == 1) ret += cnt[k] * A;
            else if(cnt[k] == 2) ret += cnt[k] * B;
            else if(cnt[k] == 3) ret += cnt[k] * C;
        }
    }

    cout << ret;

    return 0;
}