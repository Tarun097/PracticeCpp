/*
 *Unordered sets are containers that store unique elements in no particular order
 *In an unordered_set, the value of an element is at the same time its key, that identifies it uniquely.
 *Keys are immutable, therefore, the elements in an unordered_set cannot be modified once in the container - they can be inserted and removed, though.
 *
 * Internally, the elements in the unordered_set are not sorted in any particular order,
 * but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their values (with a constant average time complexity on average)
 *
 * All operations on the unordered_set takes constant time O(1) on an average
 *	which can go up to linear time O(n) in worst case which depends on the internally used hash function
 *	
 */

#include<iostream>
#include <unordered_set>

int main(int argc, char* argv)
{
	std::unordered_set<int> unordered_set{ 23,4,56,1,87 };
	unordered_set.insert(15); // O(1)

	for(auto i : unordered_set)
	{
		std::cout << i << " ";
	}

	std::cout << "\nAfter erasing 1\n";
	
	unordered_set.erase(1); // O(1)

	for (auto i : unordered_set)
	{
		std::cout << i << " ";
	}


	std::cout << "\nfinding element 56";
	auto itr = unordered_set.find(56);

	if(itr!=unordered_set.end()) //important check
	{
		std::cout << "\nfound "<<*itr << "\n";
	}

	std::cout << "Inserting a vector elements into unordered_set\n";
	std::vector<int> vector{ -1,-2,-3 };
	unordered_set.insert(vector.begin(), vector.end());

	for (auto i : unordered_set)
	{
		std::cout << i << " ";
	}


	// unordered_set.load_factor();  -- ratio of (total no. of elements) / (total no.of buckets)
	//unordered_set.bucket_count();  -- total no. of buckets
	//unordered_set.bucket(1);  -- which bucket this element x is
	
}