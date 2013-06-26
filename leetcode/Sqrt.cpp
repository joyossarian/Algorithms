class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int op  = x;
        unsigned int = 0;
        unsigned int one = 1uL << 30; // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type


        // "one" starts at the highest power of four <= than the argument.
        while (one > op)
        {
          one >>= 2;
        }

        while (one != 0)
        {
          if (op >= res + one)
          {
            op = op - (res + one);
            res = res +  2 * one;
          }
          res >>= 1;
          one >>= 2;
        }
      return res;
    }
};
