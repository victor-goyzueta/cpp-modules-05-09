#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& container, const int value)
{
	typename T::iterator it =
		std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, const int value)
{
	typename T::const_iterator it =
		std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	return it;
}
