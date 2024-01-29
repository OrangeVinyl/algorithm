#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // <트럭의 무게, 트럭이 다리에 진입한 시간>
    queue<pair<int,int>> bridge;

    // time : 현재까지 경과한 시간, cur: 현재 다리 위 트럭들의 무게 합
    int time = 0, cur = 0;

    for(int i = 0; i < truck_weights.size(); i++) {
        time++;

        // 현재 시간이 다리의 가장 앞에 있는 트럭이 다 건넌 시간에 다리의 길이를 더한 시간과 같을 때
        if (time == bridge.front().second + bridge_length) {
            cur -= bridge.front().first;
            bridge.pop();
        }
        
        // 현재 다리 위의 트럭들의 무게 합과 새로 들어올 트럭의 무게 합이 다리 최대 중량을 넘는 경우
        while(cur + truck_weights[i] > weight) {
            time = bridge.front().second +  bridge_length;
            cur -= bridge.front().first;
            bridge.pop();
        }

        // 새로운 트럭 추가
        cur += truck_weights[i];
        bridge.emplace(truck_weights[i], time);
    }


    time = bridge.back().second + bridge_length;

    return time;
}

/**
 * 핵심 아이디어: 결국 모든 트럭은 저 다리 길이를 건너야 하기 때문에 일일이 더할 필요가 없다. 한꺼번에 더해버리자.
 */