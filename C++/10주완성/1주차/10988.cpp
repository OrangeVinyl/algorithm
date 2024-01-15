// 백준 10988 | 팰린드롬인지 확인하기
#include <bits/stdc++.h>
using namespace std;

string a,b;
int main() {
    cin >> a;
    b = a;
    reverse(a.begin(), a.end());
    if (b == a) {
        cout <<  1;
    } else {
        cout << 0;
    }
    
    return 0;
}