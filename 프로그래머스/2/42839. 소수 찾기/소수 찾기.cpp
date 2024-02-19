#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;
vector<char> detail;
set<int> t;
int answer;

bool isPrimeNumber(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void permutation() {
    sort(detail.begin(), detail.end()); 
    
    do {
        for (int i = 1; i <= detail.size(); i++) { 
            string str = "";
            for (int j = 0; j < i; j++) {  
                str += detail[j];
            }
            int num = stoi(str);  
            t.insert(num); 
        }
    } while (next_permutation(detail.begin(), detail.end()));
}

int solution(string numbers) {
    for(int i = 0; i < numbers.length(); i++) {
        detail.push_back(numbers[i]);
    }
    
    // 모든 경우의 수 구하기
    permutation();
    
    // 모든 숫자 조합에서 소수 판별
    for (int i : t) {
        if (isPrimeNumber(i)) {
            answer++;
        }
    }

    return answer;
}