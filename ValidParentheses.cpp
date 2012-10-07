class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::deque<char> parenthese;
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i)
        {
            char cc = s[i];
            if (cc == '(' || cc == '{' || cc == '[')
            {
                parenthese.push_back(cc);
                continue;
            }
            else if (cc == ')')
            {
                if (parenthese.empty() || parenthese.back() != '(')
                {
                    return false;
                }
                parenthese.pop_back();
            }
            else if (cc == ']')
            {
                if (parenthese.empty() || parenthese.back() != '[')
                {
                    return false;
                }
                parenthese.pop_back();
            }
            else if (cc == '}')
            {
                if (parenthese.empty() || parenthese.back() != '{')
                {
                    return false;
                }
                parenthese.pop_back();
            }
        }
        if (!parenthese.empty())
        {
            return false;
        }
        return true;
    }
};
