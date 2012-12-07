string addBinary(string a, string b) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	string result;
	int alen = a.size() - 1;
	int blen = b.size() - 1;
	char carry = 0;
	while (alen >= 0 || blen >= 0 || carry)
	{
		char charA = 0;
		if (alen >= 0)
		{
			charA = a[alen] -'0';
		}
		char charB = 0;
		if (blen >= 0)
		{
			charB = b[blen] - '0';   
		}
		char add = charA + charB + carry;
		if (add >= 2)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		char charDigit = add % 2 + '0';
		result.push_back(charDigit);

		if (alen >= 0)
		{
			--alen;
		}
		if (blen >= 0)
		{
			--blen;
		}
	}
	std::reverse(result.begin(), result.end());
	return result;
}