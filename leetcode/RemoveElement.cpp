class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int end = n - 1;
        for (int i = 0; i < n; ++i)
        {
            int val = A[i];
            if (elem == val)
            {
                while (A[end] == val && end >= 0)
                {
                    --end;
                }
                if (end < 0)
                {
                    break;
                }
                if (i < end)
                {
                    A[i] = A[end];
                    --end;
                }
            }
        }
        return (end + 1);
    }
};
