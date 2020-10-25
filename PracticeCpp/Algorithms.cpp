#include<iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<int> vector{ 11,62,34,84,-5 };

	const auto minItr = std::min_element(vector.begin(), vector.end());
	std::cout << "Min of these is :" << *minItr << "\n";

	const auto maxItr = std::max_element(vector.begin(), vector.end());
	std::cout << "Max of these is :" << *maxItr << "\n";
	
	std::cout << "Sorted vector :" << std::endl;
	std::sort(vector.begin(), vector.end());
	for(auto i : vector)
	{
		std::cout << i << " ";
	}

	std::cout << "\nEven numbers \n";
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> even_numbers;

	std::transform(vec.begin(), vec.end(), //source
		std::back_inserter(even_numbers), //destination
		[](int x) {return (x % 2) == 0; });

	for(int i : even_numbers)
	{
		std::cout << i << " ";
	}
	
}


