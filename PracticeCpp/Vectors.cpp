#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::vector<int> list;
	list.push_back(1);
	list.push_back(12);
	list.push_back(-3);
	list.push_back(4);

	auto itr1 =list.begin();
	std::vector<int>::iterator itr2 = list.end();

	for (std::vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		std::cout << *itr << std::endl;
	}

	std::sort(itr1, itr2);

	for (std::vector<int>::iterator itr = itr1; itr != itr2; itr++)
	{
		std::cout << *itr << std::endl;
	}


	std::vector<std::string> names;
	names.push_back("ghi");
	names.push_back("abc");
	names.push_back("aac");
	names.push_back("cab");
	
	auto namesBegin = names.begin();
	std::vector<std::string>::iterator namesEnd = names.end();

	for (std::vector<std::string>::iterator itr = namesBegin; itr != namesEnd; itr++)
	{
		std::cout << *itr << std::endl;
	}

	std::sort(namesBegin, namesEnd);

	for (std::vector<std::string>::iterator itr = namesBegin; itr != namesEnd; itr++)
	{
		std::cout << *itr << std::endl;
	}
	
}
