class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if (n <= 2)
    	{
    		return 0;
    	}
    	std::vector<int> peaks;
    	if (A[0] >= A[1])
    		peaks.push_back(0);
    	for (int i = 1; i < n - 1; ++i)
    	{
    		bool noBiggerFront = true;
    		bool noBiggerBack = true;
    		int pVal = A[i];
    		for (size_t j = 0; j < i; ++j)
    		{
    			if (A[j] > pVal)
    			{
    				noBiggerFront = false;
    				break;
    			}
    		}
    		for (size_t j = i + 1; j < n; ++j)
    		{
    			if (A[j] > pVal)
    			{
    				noBiggerBack = false;
    				break;
    			}
    		}
    		if (noBiggerBack || noBiggerFront)
    		{
    			peaks.push_back(i);
    		}
    	}
    	if (n >= 2 && A[n-1] >= A[n-2])
    	{
    		peaks.push_back(n-1);
    	}
    	
    	int result = 0;
    	for (int i = 0; i < (int)peaks.size() - 1; ++i)
    	{
    		int psi = peaks[i];
    		int pse = peaks[i + 1];
    		int psHeight = A[psi];
    		int peHeight = A[pse];
    		int finalHeight = std::min(psHeight, peHeight);
    		for (int j = psi; j < pse; ++j)
    		{
    			int cHeight = A[j];
    			if (cHeight < finalHeight)
    			{
    				result += (finalHeight - cHeight);
    			}
    		}
    	}
    	return result;
    }
};
