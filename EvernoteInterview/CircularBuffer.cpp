//#Enter your code here
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class CircularBuffer
{
private:
	vector<string> container;
	size_t capacity;
	size_t count;
	int head;
	size_t listCount;

public:
	CircularBuffer(size_t cap)
		: container(cap)
		, capacity(cap)
		, count(0)
		, head(-1)
		, listCount(0)
	{
	}

	void Append(const string& s)
	{
		if (head == -1)
		{
			head = 0;
		}
		size_t slot = (head + count) % capacity;
		container[slot] = s;
		if (count == capacity)
		{
			head = (head + 1) % capacity;
		}
		else
		{
			++count;
		}
	}

	void Remove(size_t num)
	{
		head = (head + num) % capacity;
		count -= num;
	}

	size_t Count() 
	{ 
		listCount = 0;
		return count;
	}

	const string& GetNext() 
	{
		if (listCount < count)
		{
			const string& result = container[(head + listCount) % capacity];
			++listCount;
			return result;
		}
	}
};

void AppendString(CircularBuffer& buffer, size_t num)
{
	string s;
	for (size_t i = 0; i < num; ++i)
	{
		cin >> s;
		buffer.Append(s);
	}
}

void RemoveFromBuffer(CircularBuffer& buffer, size_t num)
{
	buffer.Remove(num);
}

int main()
{
	size_t BufferSize = 0;
	cin >> BufferSize;
	CircularBuffer testBuffer(BufferSize);

	string command;
	cin >> command;
	size_t num;
	while (command != "Q")
	{
		if (command == "A")
		{
			cin >> num;
			AppendString(testBuffer, num);
		}
		else if (command == "R")
		{
			cin >> num;
			RemoveFromBuffer(testBuffer, num);
		}
		else if (command == "L")
		{
			size_t count = testBuffer.Count();
			for (size_t i = 0; i < count; ++i)
			{
				cout << testBuffer.GetNext() << "\n";
			}
		}
		cin >> command;
	}
}
