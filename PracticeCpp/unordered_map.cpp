/*
 * unordered_map : unordered set of pairs
 *
 * There is NO Associative Array, but can be implemented using -  map or unordered_map
 *	 Notes about Associate Array:
 *		1. Search time : unordered_map : O(1) ; map : O(log(n))
 *		2. Unordered_map may degrade to O(n) -- because of possible hash collision
 *		3. Can't use multimap and unordered_map, they don't have [] operator
 *
 * 
 */

#include <iostream>
#include <unordered_map>

int main(int argc, char* argv[])
{
	std::unordered_map<char, std::string> days{ {'S', "Sunday"}, {'M', "Monday"} };
	std::cout << days['S'] << "\n"; //no range check
	std::cout << days.at('S') << "\n"; //has range check

	days['T'] = "Tuesday"; //Inserting {'T', "Tuesday"}
	days.insert(std::make_pair('W', "Wednesday")); //Inserting {'W', "Wednesday"}

	days.insert(std::make_pair('M', "MONDAY")); //Will fail to modify
	days['M'] = "MONDAY"; //Works - [] provides write access to container.This has below consequence

	/*
	 * void foo(const std::unordered_map<char, std::string>& m)
	 * {
	 *	 m['S'] = "SUNDAY"; //will fail because it's const
	 *	 std::cout << m['S']; //This will also fail (won't compile) as in above line 23 we have see [] provides write access
	 *
	 *	 //To print the values use find()
	 *	 auto itr = m.find('S');
	 *	 if(itr!=m.end())
	 *	 {
	 *		std::cout << *itr << std::endl;
	 *	 }
	 * }
	 */
	
}