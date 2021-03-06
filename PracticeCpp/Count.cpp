#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(int argc, char* argv[])
{
	std::vector<int> nums{ 1,2,3,4,4,5,6,7,4,3,412,3 };
	int countFour = static_cast<int>(std::count(std::begin(nums), std::end(nums), 4));

	std::cout << countFour << std::endl;

	int oddCount = std::count_if(std::begin(nums), std::end(nums), [](auto num) { return num % 2 != 0; });
	std::cout << oddCount << std::endl;

	std::cout << "Are all nums odd ? " << std::boolalpha << std::all_of(std::begin(nums), std::end(nums), [](auto num) {return num % 2 != 0; }) << std::endl;
	std::cout << "Are none of nums odd ? " << std::boolalpha << std::none_of(std::begin(nums), std::end(nums), [](auto num) {return num % 2 != 0; }) << std::endl;
	std::cout << "Is any of nums odd ? " << std::boolalpha << std::any_of(std::begin(nums), std::end(nums), [](auto num) {return num % 2 != 0; }) << std::endl;

	std::map<int, int> monthAndDays{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31} };

	int longMonths = std::count_if(std::begin(monthAndDays), std::end(monthAndDays), [](auto pair) { return pair.second == 31; });
	std::cout << longMonths;

	std::cin.get();
}
