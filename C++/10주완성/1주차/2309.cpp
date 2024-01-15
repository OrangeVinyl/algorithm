#include <bits/stdc++.h>
using namespace std;

/**
 * 문제 풀이 방법
 * 1. 순열 9P7 (next_permutation)
 * 2. 조합 9C2 (combination)
 */

// int a[9];

// int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

//    for (int i = 0; i < 9; i++) {
//         cin >> a[i];
//    }
//     sort(a, a+9);

    
//    return 0;
// }

// 조합 풀이방법
int a[9], sum;
vector<int> v;
pair <int, int> ret;

void combi() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<i; j++) {
            if (sum - a[i] - a[j] == 100) {
                ret = {i,j};
                return;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    combi();

    for (int i=0; i<9; i++) {
        if(ret.first == i || ret.second == i ) continue;
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    for(int i: v) cout << i << '\n';
    return 0;
}