#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, c, inp[1004];
map<int,int> a, b;
vector<pair<int,int>> v;

bool cmp (pair<int,int> c, pair<int,int> d) {
    if (c.first == d.first) {
        return b[c.second] < b[d.second];
    }
    return c.first > d.first;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    vector<int> tmp(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
        a[inp[i]]++;

        // map의 경우 참조만 해도 할당 및 참조되지 않아도 0으로 초기화 되기 때문에 0, i+1로 설정
        if(b[inp[i]] == 0) b[inp[i]] = i + 1;
    }

    for (auto it : a) {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        for (int j = 0; j < i.first; j++) {
            cout << i.second << ' ';
        }
    }

    return 0;
}