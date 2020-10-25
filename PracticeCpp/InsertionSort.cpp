/*
* Insertion Sort : O(n), considered better than selection and bubble sort
* 
* Start from 2nd element - first half is considered sorted, second half is unsorted 
*	    take element from unsorted side and sift elements in sorted array and place it ar right place
*		3 | 2 6 1 8
*       2 3 | 6 1 8 
*       2 3 6 | 1 8  - now 1 will be shifted by 3 places after it is compared with 6 then 3 then 2 , each moving to higher index
*       1 2 3 6 | 8  - 8 does not require shift
*/