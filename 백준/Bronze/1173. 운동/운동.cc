#include <iostream>
using namespace std;

int main()
{
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int exercise = 0;
	int rest = 0;
	int sum = m;

	if (m + T > M)
	{
		cout << -1;
		return 0;
	}

	while (exercise < N)
	{
		while (sum + T > M)
		{
			sum = sum - R;
			rest++;
			if (sum <= m)
				sum = m;
		}
		sum = sum + T;
		exercise++;
	}
	int result = exercise + rest;
	cout << result;
	return 0;
}