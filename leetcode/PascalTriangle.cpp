class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        result.resize(numRows);
        
        for (size_t i = 0; i < numRows; ++i)
        {
            vector<int>& row = result[i];
            row.resize(i + 1);
            for (size_t j = 0; j <= i; ++j)
            {
                if ((j == 0) || (j == i))
                {
                    row[j] = 1;
                }
                else
                {
                    vector<int>& pr = result[i - 1];
                    row[j] = pr[j - 1] + pr[j];
                }
            }
        }
        return result;
    }
};
