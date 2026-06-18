#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, const int i);

template<typename T>
typename T::const_iterator easyfind(const T& container, const int value);

# include "easyfind.tpp"

#endif
