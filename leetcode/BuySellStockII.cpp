class Solution {
public:
    int maxProfit(vector<int> &prices) {
    // Start typing your C/C++ solution below
  // DO NOT write int main() function
	size_t days = prices.size();
	if (days < 2)
	{
		return 0;
	}
	size_t i = 0;
	int profit = 0;
	while (i < days)
	{
		int price = prices[i];
		size_t next = i + 1;
		if (next >= days)
			break;
		int nextPrice = prices[next];
		if (nextPrice > price)
		{
			size_t j = next;
			for (; j < days; ++j)
			{
				if (prices[j] < prices[j - 1])
				{
					break;
				}
			}
			profit += (prices[j - 1] - price);
			i = j;
		}
		else
		{
			i = next;
		}
	}
	return profit;
}

};
