class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		size_t idx = 0;
		string result;
		while (true)
		{
			bool valid = false;
			for (size_t i = 0; i < strs.size(); ++i)
			{
				string& curString = strs[i];
				if (idx >= curString.size())
				{
					valid = false;
					break;
				}
				if (i >=1 && curString[idx] != strs[i -1][idx])
				{
					valid = false;
					break;
				}
				if (i == strs.size() - 1)
				{
					valid = true;
					result.push_back(curString[idx]);
				}
			}
			if (!valid)
			{
				break;
			}
			++idx;
		}
		return result;
	}
};