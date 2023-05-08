
#include <iostream>
#include <numeric>

template<typename T, size_t size>
class ArrayUtils
{
public:
	static void print(T* data)
	{
		for(size_t i = 0;i < size;i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}

	static void reversePrint(T* data)
	{
		for (int i = (size - 1); i >= 0; i--)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}

	static T sumAll(T* data)
	{
		T sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += data[i];
		}
		return sum;
	}

	static T productOfArray(T* data)
	{
		T product = 1;
		for (size_t i = 0; i < size; i++)
		{
			product *= data[i];
		}
		return product;
	}
};