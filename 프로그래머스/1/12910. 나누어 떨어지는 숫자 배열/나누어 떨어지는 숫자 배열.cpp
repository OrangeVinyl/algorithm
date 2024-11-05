#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> solution(vector<int> arr, int divisor) {

    for (int a : arr) {
        if (a % divisor == 0) answer.push_back(a);
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}