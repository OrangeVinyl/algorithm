#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

map<string, int> mp;
string a[] = {"test","test1","test2"};


int main(void) {
    for (int i = 0; i < 3; i++) {
        mp.insert({a[i], i+1});
        mp[a[i]] = i + 1;
    }

    cout << mp["kundol"] << '\n';
    mp["kundol"] = 4;
    cout << mp.size() << '\n';

    mp.erase("kundol");

    auto it = mp.find("kundol");
    if (it != mp.end()) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }

    for (auto it : mp) {
        cout << (it).first << " :  " << (it).second << '\n';
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " :  " << (*it).second << '\n';
    }

    mp.clear();

    return 0;
}

/**
 * 
범위 기반 for 루프:
auto it : mp에서 it는 컨테이너의 각 요소에 대한 값이며, it.first 및 it.second와 같이 멤버에 직접 접근할 수 있습니다.
이 경우 it는 컨테이너의 값이므로 *it을 사용할 필요가 없습니다.

일반적인 이터레이터 사용:
auto it = mp.begin();에서 it는 이터레이터이며, *it은 이터레이터가 가리키는 요소에 대한 참조입니다.
(*it).first 및 (*it).second와 같이 멤버에 접근할 때는 *it을 사용하여 이터레이터를 역참조해야 합니다.
따라서 범위 기반 for 루프를 사용할 때는 *it을 사용할 필요가 없으며, 일반적인 이터레이터를 사용할 때만 *it을 통해 역참조해야 합니다.
 * 
 */

// map <int, int> mp;
// map <string, string> mp2;
// int checkZeroAtMap(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     if(mp[1] == 0) {
//         mp[1] = 2;
//     }

//     for (auto i : mp) cout << i.first << ' ' << i.second;

//     return 0; 
// }

// int checkZeroAtMapAnother(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     if(mp.find(1) == mp.end()) mp[1] == 2;
//     for (auto i : mp) cout << i.first << ' ' << i.second;

//     return 0;
// }