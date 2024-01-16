#include <bits/stdc++.h>
using namespace std;


// 백준 10828 || 스택

stack <int> st;
string cmd;
int N, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> t;
            st.push(t);
        } else if (cmd == "pop") {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (cmd == "size") {
            cout << st.size() << '\n';
        } else if (cmd == "empty") {
            cout << st.empty() << '\n';
        } else if (cmd == "top") {
            if (st.empty()) {
                cout << -1 << '\n';
            } else {
                cout << st.top() << '\n';
            }
        }
    }


    return 0;
}
