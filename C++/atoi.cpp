#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 문자열 확인로직
 * atoi(s.c_str())를 이용하여 string으로 입력받은 문자열이 문자열인지 숫자인지 확인한다.
 * 숫자인 경우 1, 문자인 경우 0을 반환한다.
 */

int main() {
    string s = "1";
    string s2 = "amumu";
    cout << atoi(s.c_str()) << '\n';
    cout << atoi(s2.c_str()) << '\n';
    return 0;
}
