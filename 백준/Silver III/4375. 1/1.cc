#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, num = 1;
int cnt = 1;

int main () {
    while (cin >> n) {
        num = 1;
        cnt = 1;

        while(true) {
            if (num % n == 0) break;
            num = (num * 10)%n + 1%n;
            cnt++;
        }

        cout << cnt <<'\n';
    }

    return 0;
}