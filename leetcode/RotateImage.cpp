class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t n = matrix.size();
        
        // transpose
        for (size_t row = 0; row < n; ++row)
        {
            for (size_t column = row + 1; column < n; ++ column)
            {
                int temp = matrix[row][column];
                matrix[row][column] = matrix[column][row];
                matrix[column][row] = temp;
            }
        }
        
        // swap columns
        for (size_t column = 0; column < n / 2; ++column)
        {
            size_t swapColumn = n - column - 1;
            for (size_t row = 0; row < n; ++row)
            {
                int temp = matrix[row][column];
                matrix[row][column] = matrix[row][swapColumn];
                matrix[row][swapColumn] = temp;
            }
        }
    }
};
