#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int hashF(string str) {
    int ret = str.size();
    for (char a : str) ret += (int) a;

    return ret % 10;
}

int main(void) {
    // 내부적으로 구현이 안되어 있는 경우, 이런식으로 정수타입의 해시키를 만들어서 해시테이블 구현해야함
    unordered_map<int, string> umap;
    umap[hashF("paka")] = "paka";
    umap[hashF("kundol")] = "kundol";

    // unordered_map 은 해시테이블로 구현이 되어있기 때문에 내부적으로 string 값을 받아도 int 타입의 해시키를 만들고 이를 기반으로 테이블로 만든다.
    unordered_map<string,string> umap2;
    umap2["paka"] = "paka";
    umap2["kundol"] = "kundol";

    for (auto element : umap) {
        cout << element.first << " :: " << element.second << '\n';
    }

    for (auto element: umap2) {
        cout << element.first << " :: " << element.second << '\n';
    }

    cout << umap[7] << '\n';
    cout << umap2["kundol"] << "\n";

    return 0;
}


