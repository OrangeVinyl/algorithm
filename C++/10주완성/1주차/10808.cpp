// 백준 10808 | 알파벳 개수
#include <bits/stdc++.h>
using namespace std;

vector<int> cnt (26, 0);
string word;

int main() {
    cin >> word;

    for (int c : word) {
        if (isalpha(c)) {
            cnt[ c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}