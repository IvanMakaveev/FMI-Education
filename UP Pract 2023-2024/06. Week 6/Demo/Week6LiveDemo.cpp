#include <iostream>
using namespace std;

constexpr unsigned int MAX_ARRAY_SIZE = 1024;

void swapValues(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void readArray(int arr[], unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int getIndexOfPreviousLongest(
	const int sequence[],
	const unsigned int subsequenceLength[],
	int currentIndex
)
{
	unsigned int resultIndex = -1;
	unsigned int maxLength = 0;
	for (size_t i = 0; i < currentIndex; i++)
	{
		if (sequence[i] >= sequence[currentIndex])
		{
			continue;
		}

		if (resultIndex == -1 || maxLength < subsequenceLength[i])
		{
			resultIndex = i;
			maxLength = subsequenceLength[i];
		}
	}

	return resultIndex;
}

void fillSubsequenceData(
	const int sequence[],
	unsigned int size,
	unsigned int subsequenceLength[],
	int previousElement[])
{
	for (size_t i = 0; i < size; i++)
	{
		int prevLongestIndex = getIndexOfPreviousLongest(sequence, subsequenceLength, i);

		previousElement[i] = prevLongestIndex;

		if (prevLongestIndex != -1)
		{
			subsequenceLength[i] = subsequenceLength[prevLongestIndex] + 1;
		}
		else
		{
			subsequenceLength[i] = 1;
		}
	}
}

void reverseArray(int arr[], unsigned int size)
{
	for (size_t i = 0; i < size / 2; i++)
	{
		swapValues(arr[i], arr[size - i - 1]);
	}
}

int getIndexOfMax(const unsigned int arr[], unsigned int size)
{
	if (size == 0)
	{
		return -1;
	}

	unsigned int resultIndex = 0;
	unsigned int maxValue = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
			resultIndex = i;
		}
	}

	return resultIndex;
}

void fillLongestIncreasingSubsequence(
	const int sequence[],
	unsigned int size,
	int result[],
	unsigned int& resultSize)
{
	unsigned int subsequenceLength[MAX_ARRAY_SIZE];
	int previousElement[MAX_ARRAY_SIZE];

	fillSubsequenceData(sequence, size, subsequenceLength, previousElement);

	resultSize = 0;

	int maxIndex = getIndexOfMax(subsequenceLength, size);

	if (maxIndex == -1)
	{
		return;
	}

	do
	{
		result[resultSize++] = sequence[maxIndex];
		maxIndex = previousElement[maxIndex];
	} while (maxIndex != -1);

	reverseArray(result, resultSize);
}

void printArray(const int arr[], unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
}

int main()
{
	unsigned int elementsCount = 0;
	cin >> elementsCount;

	if (elementsCount < 2 || elementsCount > MAX_ARRAY_SIZE)
	{
		cout << "Incorrect data";
		return 0;
	}

	int sequence[MAX_ARRAY_SIZE];
	readArray(sequence, elementsCount);

	int result[MAX_ARRAY_SIZE];
	unsigned int resultSize = 0;
	fillLongestIncreasingSubsequence(sequence, elementsCount, result, resultSize);

	printArray(result, resultSize);
}