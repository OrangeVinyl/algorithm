#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, cnt, sum;
int total_sum;
vector<int> v;



int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    total_sum += tmp;
    v.push_back(tmp);
  }


  int lo = *max_element(v.begin(), v.end());
  int hi = total_sum;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    sum = 0;
    cnt = 0;

    for (int i : v) {
      if (sum + i > mid) {
        sum = 0;
        cnt++;
      } 
      sum += i;
    }
    
    if (sum != 0) cnt++;
    
    if (cnt > m) {
      lo = mid + 1;
    } else hi = mid -1;
  }

  cout << lo;

  return 0; 
}