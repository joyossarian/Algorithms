class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* steps = new int[n + 1];
        steps[0] = 1;
        steps[1] = 1;
        
        for (int i = 2; i <= n; ++i)
        {
            steps[i] = steps[i - 2] + steps[i - 1];
        }
        
        return steps[n];
    }
};
