#include <iostream>
#include <utility>

template <typename T1, typename T2>
class myPair
{
public:
	T1 first;
	T2 second;

	myPair(T1 first, T2 second)
	{
		this->first = first;
		this->second = second;
	}

	void operator=(std::pair<T1, T2> other)
	{
		this->first = other.first;
		this->second = other.second;
	}
};
