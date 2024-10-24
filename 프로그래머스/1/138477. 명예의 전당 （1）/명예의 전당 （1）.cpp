#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> hof;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    int days = score.size();

    for (int i = 0; i < k; i++) {
        if (i < days) { 
            hof.push_back(score[i]);
            sort(hof.begin(), hof.end());
            answer.push_back(hof[0]);
        } else break;
    }
    
    if (k > days) return answer;
    
    for (int z = k; z < days; z++) {
        if (score[z] > hof[0]) {
            hof.erase(hof.begin() + 0);
            hof.push_back(score[z]);
            sort(hof.begin(), hof.end());
            answer.push_back(hof[0]);
        } else {
            answer.push_back(hof[0]);
        }
    }

    return answer;
}