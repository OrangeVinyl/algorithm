#include <bits/stdc++.h>
using namespace std;


/**
 * @brief map을 사용하여 비교해가며 중복되는 요소를 제거
 * 
 */

map<int, int> mp;

int main() {
  vector<int> v{1, 2, 2, 3, 5, 5, 6};
  for (int i : v) {
    if (mp[i]) {
      continue;
    } else {
      mp[i] = 1;
    }
  }

  vector<int> ret;
  for (auto it : mp) {
    ret.push_back(it.first);
  }
  for (int i : ret) cout << i << '\n';
}


/**
 * @brief unique()를 사용한 중복 요소 제거
 *  unique는 범위안에 있는 요소 중 앞에서부터 서로를 ㅂ교해가며 중복되는 요소를 제거하고 나머지 요소들은 삭제하지 않고 그대로 두는 함수 
 *  O(n)의 시간복잡도를 가진다.
 */


// 예시
// before) 1 1 2 2 3 3 4 4 5 5
// after) 1 2 3 4 5 3 4 4 5 5

// 아래의 경우도 발생할 수 있기 때문에 꼭 sort()를 같이 사용해야 한다.

// before) 2 2 1 1 2 2 3 3 5 6 7 8 9
// after) 2 1 2 3 5 6 7 8 9 6 7 8 9


vector<int> v

void usingUnique() {
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);  
        v.push_back(i);  
    }

    for (int i : v) cout << i << ' ';
    cout << '\n';

    // 중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환
    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n';

    // 앞에서부터 중복되지 않게 채운 후 나머지 요소들은 그대로 둠
    for (int i : n) cout << i << ' ';
    cout << '\n';
}

void finalUnique() {
    ios_base::sync_with_stdi(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> s {4,3,3,5,1,2,3}
    sort(v.begin(), v.end())
    s.erase(unique(s.begin(), s.end()), s.end())

    for (int i : s) cout <<i << ' ';

}