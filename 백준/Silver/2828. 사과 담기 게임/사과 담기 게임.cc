#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n, m, j, dist;
vector<int> location;

int main() {
    cin >> n >> m;
    cin >> j;

    location.resize(j);
    for (int i = 0; i < j; ++i) {
        cin >> location[i];
    }

    int curr_start = 1;
    int curr_end = m;

    for (int i = 0; i < location.size(); ++i) {
        if (location[i] >= curr_start && location[i] <= curr_end) continue;
        if (location[i] < curr_start) {
            dist += curr_start - location[i];
            curr_start = location[i];
            curr_end = curr_start + m - 1;
            
        }
        if (location[i] > curr_end) {
            dist += location[i] - curr_end;
            curr_end = location[i];
            curr_start = curr_end - m + 1;
        }
    }

    cout << dist;
}