class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = 1.0;
        for (int i = m, j = 1; i <= m + n - 2; ++i, ++j)
        {
            result *= (double)(i) / (double)j;
        }
        int final = (int) result;
        return final;
    }
};
