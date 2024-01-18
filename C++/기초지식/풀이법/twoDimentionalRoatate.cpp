#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 추가적으로 180도 뒤집는 경우, temp[i][j]=key[n−i−1][m−j−1] 이렇게 코드르 짤 수 있다.
 * 
 */

const int n = 3;
const int m = 4;

void rotate_left_90 (vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();

    vector<vector<int>> temp(m, vector<int>(n,0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = key[j][m - i - 1];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}

void rotate_right_90 (vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();

    vector<vector<int>> temp(m, vector<int>(n,0));
    for (int i = 0; i <m ; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = key[n - j - 1][i];
        }
    }
    key.resize(m);
    key[0].resize(n);

    key = temp;
    return;
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>>a ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    rotate_right_90(a);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
