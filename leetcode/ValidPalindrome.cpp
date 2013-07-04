
class Solution {
public:

    bool isAlphanumeric(char c)
    {
        bool alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        return (c >= '0' && c <= '9') || alpha;
    }
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t len = s.length();
        
        if (len == 0)
            return true;
            
        int s1 = 0;
        int s2 = len - 1;
        
        while (s1 <= s2)
        {
            char c1 = s[s1];
            char c2 = s[s2];
            if ( isAlphanumeric(c1) && isAlphanumeric(c2))
            {
                if (tolower(c1) != tolower(c2))
                    return false;
                else 
                {
                    ++s1;
                    --s2;
                    continue;
                }
            }
            
            if (!isAlphanumeric(c1)) {
                ++s1;
            }
            if (!isAlphanumeric(c2)) {
                --s2;
            }      
        }
        return true;
    }
};
