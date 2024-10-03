#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    if (s[0] == '+') {
        s = s.substr(1);
        answer = stoi(s);
    } else if (s[0] == '-') {
          s = s.substr(1);
            answer -= stoi(s);
    } else {
       answer = stoi(s);
    }
    
    return answer;
}