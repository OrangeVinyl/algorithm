#include <iostream>

using namespace std;

double sum, creditSum;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  
  string name, grade;
  double credit;
  double tmp;

  for(int i = 0; i < 20; i++) {
    cin >> name >> credit >> grade;
    if(grade == "P") continue;

    creditSum += credit;
    if(grade == "F") continue;

    if (grade[0] == 'A') tmp = 4;
    else if (grade[0] == 'B') tmp = 3;
    else if (grade[0] == 'C') tmp = 2;
    else tmp = 1;

    if (grade[1] == '+') tmp += 0.5;
    
    sum += credit * tmp;
  }

  cout << sum / creditSum;
}