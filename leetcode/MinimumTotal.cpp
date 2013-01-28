class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t level = triangle.size();
        size_t num = (1 + level) * level / 2;
        vector<int> sums(num);
        
        size_t index = (level - 1) * level / 2;
        for (size_t c = 0; c < level; ++c)
        {
            sums[index + c] = triangle[level - 1][c];
        }
        
        for (int r = level - 2; r >= 0; --r)
        {
            index = (r + 1) * r / 2;
            for (size_t c = 0; c <= r; ++c)
            {
                sums[index + c] = triangle[r][c];
                
                size_t indexL = (r + 2) * (r + 1) / 2 + c;
                size_t indexR = (r + 2) * (r + 1) / 2 + c + 1;
                
                sums[index + c] += std::min(sums[indexL], sums[indexR]);
            }
        }
        return sums[0];  
    }
};
