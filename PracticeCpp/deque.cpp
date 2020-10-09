/*
 * deque (usually pronounced like "deck") is an irregular acronym of double-ended queue.
 * Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends
 * They provide a functionality similar to vectors,
 * but with efficient insertion and deletion of elements also at the beginning of the sequence, and not only at its end.
 * But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations
 * 
 */


#include<iostream>
#include <deque>

int main(int argc, char* argv[])
{

	std::deque<int> deque;

	deque.push_back(1);
	deque.push_back(2); // {1,2}

	deque.push_front(0); //{0,1,2}
	deque.push_front(-1); // {-1,0,1,2}

	std::cout << "first element is " << deque[0] << std::endl;
	std::cout << "first element is " << deque.at(0) << std::endl;
	
	std::deque<int>::iterator start = deque.begin();
	std::deque<int>::iterator end = deque.end();

	for(std::deque<int>::iterator itr = start; itr!=end; itr++)
	{
		std::cout << *itr << std::endl;
	}

	for (auto element : deque )
	{
		std::cout << element << std::endl;
	}
	
}