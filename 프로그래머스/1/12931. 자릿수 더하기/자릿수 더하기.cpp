#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int solution(int n) {
    string s = to_string(n);
    int ans = 0;
    
    for (int i = 0; i < s.size(); i++) {
        ans += s[i] - 48;
    }
    
    return ans;
} 