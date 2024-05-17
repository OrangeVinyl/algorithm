#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int a[1000004];

int main(int argc, char** argv) {
  int test_case;
  int T;
  int n, max_n;

  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case) {
	ll sum = 0;
	cin >> n;

	// 값 입력 
	for (int i = 0; i < n; i++) cin >> a[i];

	// 최댓값 주입
	max_n = a[n-1];

	// 뒤에서부터 진행
	for (int k = n-2 ; k >=0 ; k--) {
		if (a[k] > max_n) {
			max_n = a[k];
		} else {
			sum += max_n - a[k];
		}
	}

	cout << "#" << test_case << " " << sum << '\n';
  }
  
  return 0;
}