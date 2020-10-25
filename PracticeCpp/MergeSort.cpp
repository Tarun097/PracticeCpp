/*
* Merge Sort : O(nlog(n))
* 
*	1. Is a divide & conquer algorithm
*	2. Recursive algo
*   3. Stable sorting algo
*   4. Not inplace sorting algorithm - O(n) space complexity
* 
*	MergeSort(A)
	{
	 n = length(A)
	 if(n<2) return
	 mid = n/2

	 left <= array Of Size(mid)
	 right <= array Of Size(n-mid)

	 for(i=0 to mid-1) left[i] = A[i]

	 for(i=mid to n-1) right[i-mid] = A[i]

	 MergeSort(left)
	 MergeSort(right)
	 Merge(left, right, A)
	}

	Merge(left, right, A)
	{
		nL = length(left)
		nR = lenght(right)
		i = j = k =0

		//Compare left and right array and merge in parent array
		while(i<nL && j<nR)
		{
			if(left[i] <= right[j])
			{
				A[k] = left[i]
				i = i+1
			}
			else
			{
				A[k] = right[j]
				j = j+1
			}
			k++
		}
		//Copy left overs from left array if any into parent array
		while(i < nL)
		{
			A[k] = left[i]
			i++;
			k++
		}

		//Copy left overs from right array if any in parent array
		while(j < nR)
		{
			A[k] = right[j]
			j++;
			k++
		}
	}
* 
*/