class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Start typing your C/C++ solution below
      if (x == 0)
        return true;
      if (x < 0)
        return false;
      int digits = 0;
      int divide = 1;
      int val = x;
      while (val > 0)
      {
        ++digits;
        val /= 10;
        if (digits > 1)
          divide *= 10;
      }
    
      if (digits == 1)
        return true;
    
      int ld = x % 10;
      int hd = x / divide;
    
      while (ld  == hd)
      {
        x = (x - hd * divide) / 10;
        if ( x < 10)
        {
          ld = hd = x;
          break;
        }
        else
        {
          ld = x % 10;
          divide /= 100;
          hd = x / divide;
        }
      }
    
      if (ld == hd)
        return true;
      else
        return false;
    }
};
