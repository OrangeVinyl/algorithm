#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool check(string s) {
    bool containsVowel = false;  // 모음 포함 여부
    for (int i = 0; i < s.length(); ++i) {
        if (isVowel(s[i])) containsVowel = true;  // 모음이 하나라도 있으면 true

        // 모음이나 자음이 3개 연속으로 오는 경우 검사
        if (i >= 2) {
            if (isVowel(s[i]) && isVowel(s[i-1]) && isVowel(s[i-2])) return false;
            if (!isVowel(s[i]) && !isVowel(s[i-1]) && !isVowel(s[i-2])) return false;
        }

        // 같은 글자가 연속으로 오는 경우 검사 (ee, oo 제외)
        if (i >= 1) {
            if (s[i] == s[i-1] && s[i] != 'e' && s[i] != 'o') return false;
        }
    }
    return containsVowel;  // 모음을 하나라도 포함해야 함
}

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "end") break;

        cout << "<" << s << "> is " << (check(s) ? "acceptable." : "not acceptable.") << '\n';
    }
    return 0;
}