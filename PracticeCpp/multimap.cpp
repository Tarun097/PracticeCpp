/*
 * Multimap allows duplicate keys
 *
 * keys cannot be modified
 */

#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
	std::multimap<int, std::string> multimap;
	multimap.insert(std::make_pair(1, "apple"));
	multimap.insert(std::make_pair(1, "APPLE"));
	multimap.insert(std::make_pair(2, "BALL"));

	

	for(auto pair : multimap)
	{
		std::cout << pair.first << " " << pair.second << "\n";
	}

	auto it = multimap.find(1);
	std::cout << "find result : " << it->first << " " << it->second << "\n";

	//(*it).first = 4;  //Not allowed
	
	
}