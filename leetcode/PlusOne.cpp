class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t len = digits.size();
        
        vector<int> result;
        
        int carry = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            int cI = digits[i];
            int addition = carry + cI;
            carry = addition / 10;
            addition %= 10;
            result.push_back(addition);
        }
        if (carry)
        {
            result.push_back(carry);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
