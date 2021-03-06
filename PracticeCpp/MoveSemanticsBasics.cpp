/*
 *  https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners
 */

#include <algorithm>
#include <iostream>

#define PRINT(x) std::cout<< (x) << std::endl;

class Holder
{
public:
	Holder(unsigned int size)
	{
		PRINT("ctor");
		m_data = new int[size];
		m_size = static_cast<int>(size);
	}

	~Holder()
	{
		PRINT("dtor")
		delete[] m_data;
	}

	Holder(const Holder& other)
	{
		PRINT("copy ctor")

		m_data = new int[other.m_size];
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
		m_size = other.m_size;
	}

	Holder& operator=(const Holder& other)
	{
		PRINT("copy assignment operator")

		if (this == &other) return *this;

		delete[] m_data;
		
		m_data = new int[other.m_size];
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
		m_size = other.m_size;

		return *this;
	}

	//Mark you move constructors and move assignment operators with noexcept
	
	Holder(Holder&& other) noexcept
	{
		PRINT("move copy ctor")

		m_data = other.m_data;
		m_size = other.m_size;

		other.m_data = nullptr;
		other.m_size = 0;
	}

	Holder& operator=(Holder&& other) noexcept
	{
		PRINT("move copy assignment operator")

		if (this == &other) return *this;

		delete[] m_data;

		m_data = other.m_data;
		m_size = other.m_size;

		other.m_data = nullptr;
		other.m_size = 0;

		return *this;
	}
	
private:
	int* m_data;
	int m_size{ 0 };
};

Holder createHolder(int size)
{
	return Holder(size);
}

int main(int argc, char* argv[])
{
	Holder h1(1000);                // regular constructor
	Holder h2(h1);                  // copy constructor (lvalue in input)
	Holder h3 = createHolder(2000); // move constructor (rvalue in input) (1) 

	h2 = h3;                        // assignment operator (lvalue in input)
	h2 = createHolder(500);         // move assignment operator (rvalue in input)
}

//You will notice how the move constructor does not get called during (1).
//The regular constructor is called instead: this is due to a trick called Return Value Optimization (RVO).
//Modern compilers are able to detect that you are returning an object by value, and they apply a sort of return shortcut to avoid useless copies.

//RVO is only about return values (output), not function parameters (input).
//There are many places where you may pass movable objects as input parameters,
//which would make the move constructor and the move assignment operator come into play, if implemented.

//Resource Acquisition Is Initialization (RAII)
//is a C++ technique where you wrap a class around a resource (file, socket, database connection, allocated memory, ...).
//The resource is initialized in the class constructor and cleaned up in the class destructor. This way you are sure to avoid resource leaks.