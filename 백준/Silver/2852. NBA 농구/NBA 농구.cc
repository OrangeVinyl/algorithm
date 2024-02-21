#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, oneSum, twoSum, team_nm;
int score[3];
string prev_t, time_c;

int changeToInt(string s) {
  return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

void addSum(int & sum, string s) {
  sum += (changeToInt(s) - changeToInt(prev_t));
}

string printResult(int total) {
  string minute = "00" + to_string(total / 60);
  string second = "00" + to_string(total % 60);

  return minute.substr(minute.size() - 2, 2) + ":" +
         second.substr(second.size() - 2, 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> team_nm >> time_c;

    if (score[1] > score[2]) {
      addSum(oneSum, time_c);
    } else if (score[1] < score[2]) {
      addSum(twoSum, time_c);
    }

    score[team_nm]++;

    // 누적
    prev_t = time_c;
  }

  // 경기 종료까지의 합
  if (score[1] > score[2]) {
    addSum(oneSum, "48:00");
  } else if (score[1] < score[2]) {
    addSum(twoSum, "48:00");
  }

  cout << printResult(oneSum) << '\n';
  cout << printResult(twoSum) << '\n';

  return 0;
}