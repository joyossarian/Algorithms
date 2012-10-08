#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binarySearch(int A[], int begin, int end, int target)
{
	while (begin < end && begin >= 0)
	{
		int mid = begin + (end - begin) / 2;
		if (A[mid] < target)
		{
			begin = mid + 1;
		}
		else if (A[mid] > target)
		{
			end = mid - 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}

vector<int> searchRange(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> result;
	int firstTrial = binarySearch(A, 0, n, target);
	if (firstTrial == -1)
	{
		result.push_back(-1);
		result.push_back(-1);
	}
	else
	{
		int upperStart = firstTrial + 1;
		int lastUpper = firstTrial;
		int prevLastUpper = firstTrial;
		while ((lastUpper = binarySearch(A, upperStart, n, target)) != -1)
		{
			prevLastUpper = lastUpper;
			upperStart = prevLastUpper + 1;
		}

		int lowerStart = firstTrial - 1;
		int lastLower = firstTrial;
		int prevlastLower = firstTrial;
		while ((lastUpper = binarySearch(A, 0, lowerStart, target)) != -1)
		{
			prevlastLower = lastLower;
			lowerStart = prevlastLower - 1;
		}
		result.push_back(prevLastLower, prevLastUpper);
	}
	return result;
}
int main()
{
	int sarray[6] = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> result = searchRange(sarray, 6, 8)
	std::cout << std::endl;
}