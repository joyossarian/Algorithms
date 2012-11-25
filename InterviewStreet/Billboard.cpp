/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <vector>

using namespace std;

struct ProfitState
{
	long long profit;
	int lastUnselected;
};

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> profits(N);
	for (int i = 0; i < N;++i)
	{
		cin >> profits[i];
	}

	vector<vector<ProfitState> > maxProfits(N);
	for (int i = 0; i < N; ++i)
	{
		maxProfits[i].resize(2);
	}
	long long result = profits[N-1];
	
	maxProfits[N-1][1].profit = profits[N - 1];
	maxProfits[N-1][1].lastUnselected = N;
	maxProfits[N-1][0].profit = 0;
	maxProfits[N-1][0].lastUnselected = N - 1;

	for (int i = N - 2; i >= 0; --i)
	{
		int cp = profits[i];
		vector<ProfitState>& next = maxProfits[i + 1];
		ProfitState& nextUnselState = next[0];
		ProfitState& nextSelState = next[1];
		vector<ProfitState>& current = maxProfits[i];

		current[0].profit = max(nextUnselState.profit, nextSelState.profit);
		current[0].lastUnselected = i;

		if (nextSelState.lastUnselected - i > K)
		{
			long long mp = cp + nextUnselState.profit;
			long long test = mp;
			int mpIdx = nextUnselState.lastUnselected;
			for (int j = i + 2; j <= i + K; ++j)
			{
				test += profits[j -1] - maxProfits[j - 1][0].profit + maxProfits[j][0].profit;
				if (test > mp)
				{
					mp = test;
					mpIdx = j;
				}
			}
			current[1].profit = mp;
			current[1].lastUnselected = mpIdx;
		}
		else
		{
			if (nextUnselState.profit > nextSelState.profit)
			{
				current[1].profit = cp + nextUnselState.profit;
				current[1].lastUnselected = nextUnselState.lastUnselected;
			}
			else
			{
				current[1].profit = cp + nextSelState.profit;
				current[1].lastUnselected = nextSelState.lastUnselected;
			}
		}
	}
	cout << max(maxProfits[0][0].profit, maxProfits[0][1].profit) << endl;
}