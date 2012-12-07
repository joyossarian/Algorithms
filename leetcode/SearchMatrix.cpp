class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nRow = matrix.size();
        if (nRow == 0)
            return false;
        int nCol = matrix[0].size();
        int iR = 0;
        int iC = nCol - 1;
        
        while (iR < nRow && iC >= 0)
        {
            int m = matrix[iR][iC];
            if (m == target)
            {
                return true;
            }
            else if (m > target)
            {
                --iC;
            }
            else
            {
                ++iR;
            }
        }
        return false;
    }
};