class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool neg = false;
        if (x < 0)
        {
            neg = true;
            x = -x;
        }
        int result = 0;
        while (x > 0)
        {
            int mod = x % 10;
            result = 10 * result + mod;
            x = x / 10;
        }
        if (neg)
        {
            result = -result;
        }
        return result;
    }
};