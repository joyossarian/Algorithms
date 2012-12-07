void merge(int A[], int m, int B[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int insertPos = m + n - 1;
	int apos = m - 1;
	int bpos = n - 1;
	while (apos >= 0 && bpos >=0 )
	{
		if (A[apos] >= B[bpos])
		{
			A[insertPos] = A[apos];
			--apos;
		}
		else if (A[apos] < B[bpos])
		{
			A[insertPos] = B[bpos];
			--bpos;
		}
		--insertPos;
	}
	while (bpos >= 0)
	{
		A[insertPos--] = B[bpos--];
	}
}