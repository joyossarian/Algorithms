/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

char getNewChar(char c1, char c2)
{
	if (( c1 == 'a' && c2 == 'b') || (c1 == 'b' && c2 == 'a'))
	{
		return 'c';
	}
	else if ((c1 == 'a' && c2 == 'c') || (c1 == 'c' && c2 == 'a'))
	{
		return 'b';
	}
	else if ((c1 == 'b' && c2 == 'c') || (c1 == 'c' && c2 == 'b'))
	{
		return 'a';
	}
	return 0;
}

int solve(string s, bool& stop)
{
	int len = s.length();
	if (len == 1)
	{
		stop = true;
		return 1;
	}
	if (len == 2 && getNewChar(s[0], s[1]) == 0)
	{
		stop = true;
		return 2;
	}
	int result = len;
	for (size_t i = 0; i < len - 1; ++i)
	{
		if (s[i] != s[i + 1])
		{
			char newChar = getNewChar(s[i], s[i + 1]);
			string begin("");
			string end("");

			if (i > 0)
			{
				begin.append(s.begin(), s.begin() + i);
			}
			if (i < len - 2)
			{
				end.append(s.begin() + i + 2, s.end());
			}
			string newString(begin);
			newString.push_back(newChar);
			newString.append(end);
			bool newStop = false;
			int testResult = solve(newString, newStop);
			if (newStop)
			{
				result = min(testResult, result);
				stop = newStop;
				return result;
			}
		}
	}
	return result;
}

int main()
{
	size_t N;
	cin >> N;
	for (size_t i = 0; i < N; ++i)
	{
		string line;
		cin >> line;
		bool stop = false;
		int result = solve(line, stop);
		cout << result << "\n";
	}
}