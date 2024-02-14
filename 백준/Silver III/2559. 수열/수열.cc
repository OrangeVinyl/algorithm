#include <bits/stdc++.h>

using namespace std;

int n, k, ret = -10000004, t;
int psum[100004];


int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> t;
        psum[i] = psum[i-1] + t;
    }

    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i-k]);
    }

    cout << ret;
    return 0;
}