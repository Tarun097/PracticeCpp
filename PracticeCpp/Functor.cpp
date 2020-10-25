/*
 * Function objects (functors)
 *
 * A function object, or functor, is any type that implements operator()
 * This operator is referred to as the call operator or sometimes the application operator
 * Benefits :
 *  1. function object can contain state
 *  2. function object is a type and therefore can be used as a template parameter
 *
 * The C++ Standard Library contains several function objects in the <functional> header file. 
 */

#include <iostream>
#include <string>

class X
{
public:
    void operator()(std::string str)
    {
        std::cout << "Calling functor X with parameter : " << str << std::endl;
    }

	operator std::string() //type conversion function - return type comes after operator keyword
    {
        return "ToString of X";
    }
};

int main(int argc, char* argv[])
{
    X foo;
    foo("Hi");

    std::cout << static_cast<std::string>(foo);
}