int maxSubArray(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0)
	{
		return 0;
	}
	int max = A[0];
	int cSum = A[0];
	int lastIdx = 0;
	for (int i = 1; i < n; ++i)
	{
		if (A[i] >= max && max < 0)
		{
			max = A[i];
			cSum = A[i];
			lastIdx = i;
		}
		else if (A[i] >= cSum && cSum < 0)
		{
			cSum = A[i];
			if (cSum > max)
			{
				max = cSum;
			}
			lastIdx = i;
		}
		else if (cSum + A[i] >= max && lastIdx + 1 == i)
		{
			cSum += A[i];
			max = cSum;
			lastIdx = i;
		}
		else
		{
			cSum += A[i];
			lastIdx = i;
		}

	}

	return max;
}

