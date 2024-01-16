#include <bits/stdc++.h>
using namespace std;

int n, number, strike, ball, s_cnt, b_cnt, ret;
// 3자리
bool arr[1001];
string t, one, two;

int main(void) {
    cin >> n;

    // boolean 배열을 전부 true로 초기화
    memset(arr, true,sizeof(arr));

    for(int i = 123; i <= 987; i++) {
        t = to_string(i);

        // 중복값 및 0 조건 필터링
        if (t[0] == t[1] || t[1] == t[2] || t[0] == t[2]) arr[i] = false;
        if (t[0] - '0' == 0 || t[1] - '0' == 0 || t[2] - '0' == 0 ) arr[i] = false;
    }

    for(int i = 1; i <= n ; i++) {
        cin >> number >> strike >> ball;

        for(int i = 123; i <= 987; i++) {
            // 순회 시 초기화
            s_cnt = 0;
            b_cnt = 0;
            
            // 범위 내 존재 (123 ~ 987, 중복값, 0 제외)
            if (arr[i]) {
                one = to_string(number);
                two = to_string(i);
                
                // 스트라이크 볼 판정
                for(int j = 0; j < 3; j++) {
                    for(int k = 0; k < 3; k++) {
                        if (j == k && one[j] == two[k]) s_cnt++;
                        if (j != k && one[j] == two[k]) b_cnt++;
                    }
                }
                
                // 스트라이크 또는 볼이 아닌 경우
                if (s_cnt != strike || b_cnt != ball) arr[i] = false;
            }
        }
    }

    for(int i = 123; i <= 987; i++) {
        if (arr[i]) ret++;
    }

    cout << ret;

    return 0;
}