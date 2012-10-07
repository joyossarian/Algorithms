class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sums;
        sums.resize(m);
        for (int i = 0; i < m; ++i)
        {
            sums[i].resize(n);
        }
        
        int sumValue = grid[0][0];
        sums[0][0] = sumValue;
        for (int i = 1; i < n; ++i)
        {
            sums[0][i] = sumValue + grid[0][i];;
            sumValue = sums[0][i];
        }
        
    	sumValue = grid[0][0];
        for (int i = 1; i < m; ++i)
        {
            sums[i][0] = sumValue + grid[i][0];
			sumValue = sums[i][0];
        }

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				sums[i][j] = std::min(sums[i-1][j], sums[i][j-1])
					+ grid[i][j];
			}
		}

		return sums[m-1][n-1];
    }
};