#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> dic;
string dic_arr[100004], pok_mon, quiz;

int main() { 
    // 입출력 싱크 조절
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> pok_mon;

        dic.insert({pok_mon, i});
        dic_arr[i] = pok_mon;
    }

    for (int i = 0; i < m; ++i) {
        cin >> quiz;

        if (atoi(quiz.c_str()) == 0) {
            cout << dic[quiz] << '\n';
        } else {
            cout << dic_arr[atoi(quiz.c_str())] << '\n';
        }
    }

    return 0; 
}