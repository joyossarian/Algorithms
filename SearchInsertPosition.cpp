class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] == target)
            {
                return i;
            }
            else if (A[i] < target)
            {
                result = i + 1;
            }
            else
            {
                break;
            }
        }
        return result;
    }
};