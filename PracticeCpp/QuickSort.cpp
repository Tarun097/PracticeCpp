/*
* QuickSort:
*	1. Divide & Conquer
*	2. Recursive
*	3. Not Stable
*	4. Time Complexity 
*			O(nlog(n)) - best or average case
*			O(n^2) - worst case
*	5. In place 
*	6. Most standard lib sort() uses quicksort
* 
*	QuickSort(A , start, end)
*	{
*		if(start < end)
		{
			pivotIndex = Partition(A, start, end)
			QuickSort(A, start, pivotIndex-1)
			QuickSort(A, pivotIndex+1, end)
		}
*	}
* 
*	int Partition(A, start, end)
	{
		pivot = A[end];
		pIndex = start
		for(i = start to end-1)
		{
			if(A[i]<=pivot)
			{
				swap(A[i], A[pIndex])
				pIndex = pIndex+1
			}
		}
		swap(A[pIndex], A[end])
		return pIndex
	}
* 
*   
* 
* 
* 
* 
*/