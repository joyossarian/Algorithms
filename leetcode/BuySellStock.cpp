class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2)
            return 0;
            
        int buyPrice = prices[0];
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            int& todayPrice = prices[i];
            int tryProfit = todayPrice - buyPrice;
            if (tryProfit > profit)
            {
                profit = tryProfit;
            }
            else if (todayPrice < buyPrice)
            {
                buyPrice = todayPrice;
            }
        }
        return profit;
    }
};
