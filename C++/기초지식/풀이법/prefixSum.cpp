#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 누적합 문제 예시
 * '구간쿼리' 문제가 나오면 팬윅트리, 누적합을 사용할 수 있다.
 *  뒤에서부터 누적합을 구하는 suffix sum은 코테에서 나오지 않는 편이다.
 */


int a [100004], b, c, psum[100004], n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin  >> n >> m;
    for (int i = 1 ; i < n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] +  a[i];
    }

    for (int i = 0; i < m;  i++) {
        cin >> b >> c;
        cout << psum [c] - psum[b-1] << '\n';
    }
    return  0;
}

