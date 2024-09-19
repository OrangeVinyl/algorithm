#include <iostream>
#include <vector>

void Solve(int end, std::vector<int64_t>& count);

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n; // end
	std::cin >> n;
	std::vector<int64_t> count(10);

	Solve(n, count);

 	for (auto& c : count)
		std::cout << c << ' ';
}

// 범위 맞춰주는 영역(start의 1의 자리를 0으로, end의 1의 자리를 9로)의 값 처리
void subCounting(int num, std::vector<int64_t>& count, int tenPower)
{
	while (num)
	{
		count[num % 10] += tenPower;
		num /= 10;
	}
}

void Solve(int end, std::vector<int64_t>& count)
{
	int start = 1;
	int tenPower = 1;

	while (start <= end)
	{
		while (0 != start % 10 && start <= end)
		{
			subCounting(start, count, tenPower);
			start++;
		}

		if (end < start)
			return;

		while (9 != end % 10 && start <= end)
		{
			subCounting(end, count, tenPower);
			end--;
		}

		start /= 10; end /= 10;

		for (int i = 0; i < 10; i++)
			count[i] += (end - start + 1) * tenPower;
		tenPower *= 10;
	}
}