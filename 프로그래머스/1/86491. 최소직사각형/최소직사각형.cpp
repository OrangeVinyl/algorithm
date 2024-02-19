#include <string>
#include <vector>

using namespace std;

int max_w, max_h;

int solution(vector<vector<int>> sizes) {
    
    for(vector<int> nameCard : sizes) {
        if (nameCard[0] <= nameCard[1]) {
            max_w = max(max_w, nameCard[0]);
            max_h = max(max_h, nameCard[1]);
        } else {
            max_w = max(max_w, nameCard[1]);
            max_h = max(max_h, nameCard[0]);
        }
    }
    
    return max_w * max_h;
}