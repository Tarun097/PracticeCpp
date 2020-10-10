/*
 * Multiset allows duplicate items, so insertion into multiset is always successful
 */

#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
	std::multiset<int> multiset;
	multiset.insert(1);
	multiset.insert(1); //allow duplicate insertion
	multiset.insert(2);
	multiset.insert(-2);
	
	for(auto i : multiset)
	{
		std::cout << i << std::endl;
	}

	std::cout << "\n";
	if(multiset.erase(-2))
	{
		std::cout << "erased successfully \n";
	}
	
	for (auto i : multiset)
	{
		std::cout << i << std::endl;
	}
}