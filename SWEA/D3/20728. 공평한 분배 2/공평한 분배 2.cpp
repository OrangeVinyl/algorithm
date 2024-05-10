#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("input.txt", "r", stdin);
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> x;

		int a, b;
		cin >> a >> b;

		for (int i = 0; i < a; i++) {
			int num;
			cin >> num;
			x.push_back(num);
		}

		sort(x.begin(), x.end(),greater<>());
		
		int min1 = 1e9;
		for (int i = 0; i < x.size(); i++) {
			if (i + (b-1)< x.size()) {
				min1 = min(x[i] - x[i + (b - 1)], min1);
			}
		}

		cout << "#" <<test_case << " " << min1<<"\n";
	}
	return 0;
}