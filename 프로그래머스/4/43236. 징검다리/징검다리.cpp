#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전형적인 parametric search 문제 
// 각 지점 사이의 거리가 (조건)에 만족 가능? - 그 중 최댓값
// 내가 찍은 최대 간격에서 돌을 뺏을 경우, 최소 간격으로 만들 수 있나? 로 생각해야 됨.

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int lo = 1;
    int hi = distance;
    int cnt; 
    int prev;
    
    sort(rocks.begin(), rocks.end()); // 이분탐색의 기본 조건 - 정렬
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2; // 최대 간격을 이분탐색 한다.
        cnt = 0;
        prev = 0;
        
        for (int i = 0; i < rocks.size(); i++) {
            // 현재 간격이 최대 간격보다 작은 경우 돌 제거(cnt로 대체)
            if (rocks[i] - prev < mid) {
                cnt++;
            } else prev = rocks[i];
        }
        
        if (mid > distance - prev) cnt++; // 도착지점과 마지막 돌 사이 간격 확인
        
        if (cnt <= n) {
            answer = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    
    return answer;
}