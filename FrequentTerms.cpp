//#Enter your code here
//#Enter your code here
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	size_t num;
	cin >> num;
	typedef map<string, size_t> SCounter;
	SCounter stringCounter;
	for (size_t i = 0; i < num; ++i)
	{
		string s;
		cin >> s;
		if (stringCounter.find(s) == stringCounter.end())
		{
			stringCounter[s] = 1;
		}
		else
		{
			stringCounter[s] = stringCounter[s] + 1;
		}
	}
	cin >> num;
	vector<pair<string, size_t> > top;
	SCounter::iterator iter = stringCounter.begin();
	while (iter != stringCounter.end())
	{
		size_t insertPos = top.size();
		for (size_t i = 0; i < top.size(); ++i)
		{
			if (top[i].second > iter->second)
			{

			}
			else if (top[i].second < iter->second)
			{
				insertPos = i;
				break;
			}
			else if ((top[i].second == iter->second) && (iter->first < top[i].first))
			{
				insertPos = i;
				break;
			}
		}
		top.insert(top.begin() + insertPos, make_pair(iter->first, iter->second));
		if (top.size() > num)
			top.resize(num);
		++iter;
	}
	for (size_t i = 0; i < top.size();++i)
	{
		cout << top[i].first << "\n";
	}
}
