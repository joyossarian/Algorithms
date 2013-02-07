class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p1 = m - 1;
        int p2 = n - 1;
        int p3 = (p1 + p2);
        double result = 1.0;
        for (int i = p1 + 1, j = 1; i <= p1 + p2; ++i, ++j)
        {
            result *= (double)(i) / (double)j;
        }
        int final = (int) result;
        return final;
    }
};
