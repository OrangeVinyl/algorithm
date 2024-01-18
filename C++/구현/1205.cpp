#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 1. 랭킹이 나오기 때문에 굳이 내림차순으로 정렬 할 필요가 없다
 * 2. 결국에 내가 출력해야 하는 건 새로운 숫자에 대한 랭킹이다
 *      - 랭킹을 1에서부터 증가하는건?
 * 3. 랭킹 리스트의 유효범위는 10 <= P <= 50 이기 때문에 큰 알고리즘이 필요 없을 것 같다
 * 
 * 4. N은 P 보다 더 작기 때문에 리스트의 크기도 작다.
 * 
 * 예외 케이스
 * 1. 랭킹에 안들어가는 경우 -1
 * 2. N이 0인 경우
 * 
 */

int main(void) {
    int n, score, p;
    int list[100];    
    cin >> n >> score >> p;
    
    int list[100];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    // 랭킹 유효범위 카운팅
    int cnt = 0;
    // 실제 랭크
    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (list[i] > score) {
            rank++;
        } else if (list[i] == score) {
            rank = rank;
        } else break;
        
        cnt++;
    }

    if (cnt == p) rank = -1;
    if (n == 0) rank = 1;

    cout << rank << '\n';

    return 0;
}



int second(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> v;
	int N,score,P;
	cin >> N >> score >> P;
	int rank = 1;
	
	for(int i = 0; i < N; i++) { // 점수 입력받기 
		int x;
		cin >>x;
		v.push_back(x);
	}
	
	if(N == P && v[N-1] >= score) //리스트가 꽉찬 상태에서 가장낮은점수와 같거나 작으면 rank=-1 
		rank = -1;
	else {
		for(int i = 0; i < N; i++){ //그 이외의경우 리스트보다 값이큰 수의 개수를 카운트 
			if(v[i] > score)
				rank++;
		}
	}
	cout<<rank<<'\n';
	return 0;
}