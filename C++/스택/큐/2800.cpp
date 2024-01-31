#include <bits/stdc++.h>

using namespace std;

string str;
set<string> res;
stack<int> stk;
vector<pair<int, int>> indexes;
vector<pair<int, int>> current;

void generateAndAddToSet(string s, const vector<pair<int, int>>& indexes) {
    string modified = s;
    for (auto& p : indexes) {
        modified[p.first] = modified[p.second] = '&';  
    }
    modified.erase(remove(modified.begin(), modified.end(), '&'), modified.end());  
    res.insert(modified);
}

void combine(vector<pair<int, int>>& indexes, vector<pair<int, int>>& current, int start) {
    for (int i = start; i < indexes.size(); ++i) {
        current.push_back(indexes[i]);
        generateAndAddToSet(str, current);
        combine(indexes, current, i + 1);
        current.pop_back();
    }
}

int main() {
    getline(cin, str);

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            stk.push(i);
        } else if (str[i] == ')') {
            indexes.push_back({stk.top(), i});
            stk.pop();
        }
    }

    combine(indexes, current, 0);

    for (auto& s : res) {
        cout << s << endl;
    }

    return 0;
}