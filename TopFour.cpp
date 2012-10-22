//#Enter your code here
#include <iostream>
#include <algorithm>
using namespace std;

class TopFour
{
public:
	int tf[4];
	int count;
	int max4;
	int max4Idx;

	TopFour()
		: count(0)
		, max4Idx(-1)
	{
	}

	void update(int i)
	{
		if (count < 4)
		{
			tf[count] = i;
			++count;
			return;
		}
		max4 = tf[0];
		max4Idx = 0;
		for (size_t i = 1; i < count; ++i)
		{
			if (tf[i] < max4)
			{
				max4Idx = i;
				max4 = tf[i];
			}
		}
		if (max4 < i)
		{
			tf[max4Idx] = i;
		}
	}

	void output()
	{
		sort(tf, tf + count);
		reverse(tf, tf + count);
		for (size_t i = 0; i < count; ++i)
		{
			cout << tf[i] << "\n";
		}
	}
};

int main()
{
	size_t num;
	cin >> num;
	TopFour tf;
	for (size_t i = 0; i < num; ++i)
	{
		int integer;
		cin >> integer;
		tf.update(integer);
	}
	tf.output();
}
