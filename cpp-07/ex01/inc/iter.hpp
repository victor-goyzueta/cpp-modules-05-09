#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template <typename T>
void	iter(T *array, size_t array_length, void (*func)(T &))
{
	for (size_t i = 0; i < array_length; ++i)
		func(array[i]);
}

#endif
