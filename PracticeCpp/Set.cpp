/*
 *Sets are containers that store unique elements following a specific order.
 *
 *Sets are typically implemented as binary search trees.
 */


#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
	std::set<int> set { 2,3,1,17 };

	set.insert(23); // insertion always O(log(n))
	set.insert(-1);

	auto ret = set.insert(4); //trying to insert duplicate value
	std::set<int>::iterator itr = set.begin();
	
	if (ret.second)  // whether insertion was successful 
	{
		itr = ret.first;   //iterator pointing to inserted element
		for(auto iter = itr; iter!=set.end(); iter++)
		{
			std::cout << *iter << "\n";
		}
	}

	std::cout << std::endl;
	
	for(auto i : set)
	{
		std::cout << i << std::endl;
	}

	auto iterator = set.find(2);
	set.insert(iterator, 15);   //here iterator is just a hint used to find position where 15 will be inserted
	//if good hint is provided, can reduce insertion time from O(log(n)) => O(n)

	set.erase(iterator); // will remove 2 from the set
	set.erase(15); //erase by value - O(log(n)) used to search and then delete

	//Sequence containers don't provide erase() using value - as search will take O(n)
	
}