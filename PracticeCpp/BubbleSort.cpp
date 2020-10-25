/*
* Bubble Sort : O(n^2), in-place , stable sorting
* 
* Compare first two adjacent element and swap if one greater than other, in first pass largest element will bubble up to end
*	now start again from first element, compare it with adjacent element, swap if one greater than other
*		So in each pass the largest element will bubble up to end.
*			End part of array will be sorted.
*/

#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* arr, int size)
{
	for (int pass = 1; pass < size; pass++) //No of passes
	{
		int flag = 0;
		for (int i = 0; i < size - pass; i++) // In each pass compare adjacent element and swap them if one greater than other
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}

int main(int argc, char* argv[])
{
	int arr[]{ 12,64,23,74,23,6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, size);

	BubbleSort(arr, size);

	printArray(arr, size);
}