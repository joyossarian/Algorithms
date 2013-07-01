class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.empty() || triangle[0].empty())
            return 0;
        size_t tsize = triangle.size();
        vector<vector<int> > minimums(tsize);
        
        for (size_t i = 0; i < tsize; ++i)
        {
            vector<int>& row = triangle[i];
            vector<int>& rmin = minimums[i];
            size_t rsize = row.size();
            rmin.resize(rsize);
            for (size_t j = 0; j < rsize; ++j)
            {
                if (i == 0)
                {
                    rmin[j] = row[j];
                }
                else if (j == 0)
                {
                    rmin[j] = minimums[i - 1][j] + row[j];
                }
                else if (j == rsize - 1)
                {
                    rmin[j] = minimums[i - 1][j - 1] + row[j];
                }
                else
                {
                    rmin[j] = min(minimums[i - 1][j - 1], minimums[i - 1][j]) + row[j];
                }
            }
        }
        vector<int> lastRow = minimums[tsize - 1];
        int result = lastRow[0];
        for (size_t i = 1; i < lastRow.size(); ++i)
        {
            if (lastRow[i] < result)
            {
                result = lastRow[i];
            }
        }
        return result;
    }
};
