/*
 * Selection sort : O(n^2) , in place
 * 
 * Go thorugh array from i=0 to i=n - select the min element, swap it with first element
 *					Go through array from i=1 to i=n - select min of the elements, swap with second element
 *							Go through array from i=2 to i=n - select min of the elements, swap with third element
 * 
 * 
 * 
 */

#include <iostream>

void SelectionSort(int* arr, int size)
{
	std::cout << "\nSelection Sort" << std::endl;
	for (int i = 0; i < size-1; i++)
	{
		int min = i;
		for(int j=i+1; j<size; j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}

		//move arr[min] to ith location
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void printArray(int* arr, int size)
{
	for(int i=0; i< size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int arr[]{ 12,2,-23,4 };
	printArray(arr, 4);

	SelectionSort(arr, 4);

	printArray(arr, 4);
}