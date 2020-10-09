/*
 * List containers are implemented as doubly-linked lists
 *
 * Lists are sequence containers that allow constant time
 * insert and erase operations anywhere within the sequence, and iteration in both directions.
 *
 * fast insert or remove at any place : O(1)
 * slow search : O(n) - slower than vector, because of locality of data (not in contiguous memory)
 */

#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::list<int> myList;
	myList.push_back(1);
	myList.push_back(2);

	myList.push_front(0);
	myList.push_front(-1);

	for(auto itr = myList.begin(); itr!=myList.end(); itr++)
	{
		std::cout << *itr <<std::endl;
	}
	std::cout << std::endl;

	
	std::list<int>::iterator itr = std::find(myList.begin(), myList.end(), 1);
	myList.insert(itr, 1);

	
	for(auto i : myList)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;

	myList.erase(--itr);

	for (auto i : myList)
	{
		std::cout << i << std::endl;
	}
	
	//List lack direct access to the elements by their position
	//std::cout << myList[0];
	
	//consume some extra memory to keep the linking information associated to each element

	//People use it for splice : It takes constant time O(1)
	std::cout << std::endl;

	std::list<int> list1{ 1,2,3 };
	std::list<int> list2{ 1,2,3,4,5,6,7 };

	auto list2itr = std::find(list2.begin(), list2.end(), 4);

	//from list2 take elements from 4 till end, cut them and join to list 1
	list1.splice(list1.end(), list2, list2itr, list2.end());
	

	for (auto i : list1)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;


	for (auto i : list2)
	{
		std::cout << i << std::endl;
	}
}