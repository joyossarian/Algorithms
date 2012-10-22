#include <iostream>
#include <vector>

using namespace std;

int main()
{
	size_t num;
	cin >> num;
	vector<int> input(num);
	long long nonZeroWhole = 0;
	size_t zeroNum = 0;
	for (size_t i = 0; i < num; ++i)
	{
		int integer;
		cin >> integer;
		input[i] = integer;
		if (integer != 0)
		{
			if (nonZeroWhole == 0)
			{
				nonZeroWhole = integer;
			}
			else
			{
				nonZeroWhole *= integer;
			}
		}
		else
		{
			++zeroNum;
		}
	}
	for (size_t i = 0; i < num; ++i)
	{
		int cInput = input[i];
		if (cInput == 0)
		{
			if (zeroNum == 1)
			{
				cout << nonZeroWhole << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else 
		{
			if (zeroNum >= 1)
			{
				cout << 0 << "\n";
			}
			else
			{
				long long result = nonZeroWhole / cInput;
				cout << result << "\n";
			}
		}
	}
}
