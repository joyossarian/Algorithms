int removeDuplicates(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0)
	{
		return 0;
	}
	int i = 1;
	int len = 1;
	int lastWrite = 1;
	int lastElem = A[0];
	while (i < n)
	{
		while (A[i] == lastElem)
		{
			++i;
		}
		if (i >= n)
		{
			break;
		}
		A[lastWrite] = A[i];
		lastElem = A[i];
		++lastWrite;
		++len;
		++i;            
	}
	return len;
}
