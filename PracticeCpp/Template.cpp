#include <iostream>

template <typename T>
T square(T value)
{
	return value * value;
}


template <class T>
class MyVector
{
private:
	T arr[100];
	int size;
public :
	MyVector() :size(0){}

	void print() const
	{
		for(int i=0; i<size; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	void push(T value)
	{
		if(size==100)
		{
			throw std::out_of_range("index out of bound");
		}
		arr[size++] = value;
	}

	T pop()
	{
		if(size==0)
		{
			throw std::out_of_range("index out of bound");
		}
		return arr[--size];
	}

	int getSize() const
	{
		return  size;
	}

	T getElementAt(int i) const
	{
		return arr[i];
	}

	MyVector<T> operator*(const MyVector<T>& rhs)
	{
		MyVector<T> temp;
		for(int i=0; i<size; i++)
		{
			temp.push(arr[i] * rhs.getElementAt(i));
		}
		return temp;
	}
};

template <typename T>
MyVector<T> operator*(MyVector<T>& lhs, MyVector<T> rhs)
{
	MyVector<T> temp;
	for(int i=0; i<lhs.getSize(); i++)
	{
		temp.push(lhs.getElementAt(i) * rhs.getElementAt(i));
	}
	return temp;
}

int main(int argc, char* argv[])
{
	//std::cout << square<int>(5) << std::endl;
	//std::cout << square<double>(5.5) << std::endl;

	MyVector<int> my_vector;
	my_vector.push(5);
	my_vector.push(10);
	my_vector.push(15);

	MyVector<int> my_vector1;
	my_vector1.push(5);
	my_vector1.push(10);
	my_vector1.push(15);

	const auto res1 =  my_vector * my_vector1;
	res1.print();
	
	auto res = square(my_vector);
	res.print();
	

}