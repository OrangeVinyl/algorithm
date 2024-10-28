#include <string>
#include <vector>

using namespace std;

int a[10];
int solution(vector<int> numbers) {
    int answer = 0;
    for (int i = 0; i < numbers.size(); i++) {
       a[numbers[i]] = 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (a[i] == 0) answer += i;
    }
    
    return answer;
}