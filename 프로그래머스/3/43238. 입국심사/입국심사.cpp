#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 이분탐색 할 부분 - n명일 경우, 최소 시간(1) ~ 최대 시간

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
    sort(times.begin(), times.end());
    
    ll lo = 1;
    ll hi = (ll)times[times.size() - 1] * n;
    
    while (lo <= hi) {
        ll mid  = (lo + hi) / 2;
        ll cnt = 0;
        
        for (int i = 0; i < times.size(); ++i) {
            cnt += mid / times[i];
        }
        
        if (cnt >= n) {
            answer = mid;
            hi = mid - 1;    
        } else {
            lo = mid + 1;
        }
    }
    
    return answer;
}
