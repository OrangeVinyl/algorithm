#include <bits/stdc++.h>
using namespace std;

// vector<string> split(string input, string delimiter) {
//   vector<string> ret;
//   long long pos = 0;
//   string token = "";

//   while ((pos = input.find(delimiter)) != string::npos) {
//     token = input.substr(0, pos);
//     ret.push_back(token);
//     input.erase(0, pos + delimiter.length());
//   }

//   ret.push_back(input);
//   return ret;
// }

// 더 빠른 방법

vector<string> split(const string& input, string delimiter){
  vector<string> result;
  auto start = 0;
  auto end = input.find(delimiter);

  while (end != string::npos){
    result.push_back(input.substr(start, end - start));
    start = end + delimiter.size();
    end = input.find(delimiter, start);
  }

  result.push_back(input.substr(start));
  return result;
}

int main() {
  string s = "안녕하세요 split 테스트 입니다.", d = " ";
  vector<string> a = split(s, d);
  for (string b : a) cout << b << '\n';
}