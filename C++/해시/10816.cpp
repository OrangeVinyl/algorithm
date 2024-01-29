#include <bits/stdc++.h>
using namespace std;

int n,m, card;
unordered_map<int, int> mp;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> mp[card];
        mp[card]++;
    }

    cin >> m;
    for (int i = 0; i < m; m++) {
        cin >> card;
        cout << mp[card]<< ' ';
    }

    return 0;
}

/*
N --> 상근이가 가지고 있는 숫자 카드 갯수
숫자 카드에 적혀있는 정수 
정수 하나 M
갯수를 찾아야 할 정수 M개
*/