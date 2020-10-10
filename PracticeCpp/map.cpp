// keys cannot be modified
// (*it).first = 'a'; //error

#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
	std::map<char, std::string> map;
	map.insert(std::pair<char, std::string>('M', "Monday")); //class template cannot infer type on it's own
	map.insert(std::make_pair('T', "Tuesday")); //function template can infer type on it's own

	for(auto i : map)
	{
		std::cout << i.first << " : " << i.second << std::endl;
	}

	auto it = map.find('M'); // O(log(n))
	std::cout << "find result : " << it->first << " " << it->second << std::endl;

	for(std::map<char, std::string>::iterator itr = map.begin(); itr!=map.end(); itr++)
	{
		std::cout << (*itr).first << " "<< (*itr).second << std::endl;
	}
}