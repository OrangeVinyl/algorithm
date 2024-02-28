#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int money[100001]={0,}, N=0, M=0;
  int sumMoney = 0;
  cin >> N >> M;

  for (int i=0; i < N; i++)
  {
    cin >> money[i];
    sumMoney += money[i];
  }

  int left = *max_element(money, money + N), right = sumMoney, mid = 0;
  while (left <= right)
  {
    mid = (left + right) / 2;
    int temp = mid, count = 1;

    for (int i = 0; i < N; i++)
    {
      if (temp < money[i])
      {
        count++;
        temp = mid;
      }
      temp -= money[i];
    }
    if (count <= M)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  cout << mid;

  return 0;
}