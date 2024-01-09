#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
vector<int> a {1,2,3,3,4,100};
vector<int> b {1,3,5,5,7,8,8,10,10,11,13};

int main() {
   
}
// lower_bound가 가리키는 요소 출력 ex) 100
void example() {
    cout << *lower_bound(a.begin(), a.end(), 100) <<'\n';
}

// 특정 숫자가 몇개 들어가 있는지 확인하는 로직 ex)3
void example2() {
    cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(),a.end(),3) << '\n';
}

// 특정 범위 내의 값이 몇개 있는지 확인하는 로직 ex) 5 이상 11 이하의 숫자가 몇개 있는지
void example3() {
     cout << '5 이상 11 이하의 갯수 : ' << upper_bound(b.begin(), b.end(),11) - lower_bound(b.begin(), b.end(),5);
}