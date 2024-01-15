// 백준 1159 | 농구 경기
#include <bits/stdc++.h>
using namespace std;

int N, alpha[26], nick_name[154];
string s;
vector<char> ret;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> s;
        alpha[s[0] - 'a'] += 1;
    }

    for (int j = 0; j < 26; j++) {
        if ( alpha[j] >= 5 ) {
            ret.push_back(char(j + 97));
        }
    }

    if (ret.size() == 0) {
        cout << "PREDAJA";
    } else {
        for (char c : ret) {
            cout << c;
        }
    }

    return 0;
}