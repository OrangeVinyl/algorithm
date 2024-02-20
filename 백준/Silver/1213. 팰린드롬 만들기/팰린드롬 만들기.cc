#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt[200], flag;
string s, ret;
char mid;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  for (char a : s) cnt[a]++;

  for (int i = 'Z'; i >= 'A'; --i) {
    if (cnt[i]) {
      // cnt[i] 가 홀수인 경우
      if (cnt[i] & 1) {
        mid = char(i);
        flag++;
        // 위의 if문에 존재하기 때문에 하나씩 줄이기
        cnt[i]--;
      }
      // 홀수가 2개 이상인 경우
      if (flag == 2) break;
      // 짝수의 경우, 앞 뒤에 붙이기
      for (int j = 0; j < cnt[i]; j += 2) {
        ret = char(i) + ret;
        ret += char(i);
      }
    }
  }
  
  // 홀수가 존재한다면 중앙에 삽입.
  if (mid) {
    ret.insert(ret.begin() + ret.size()/2, mid);
  }

  if (flag == 2) cout << "I'm Sorry Hansoo\n";
  else cout << ret;
  return 0;
}
