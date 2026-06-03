#include "../inc/Array.hpp"

#include <iostream>
#include <stdexcept>

template <typename T>
Array<T>::Array()
{
	this->_data = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n )
{
	this->_data = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array( const Array& copy )
{
	this->_size = copy.size();
	this->_data = new T[this->_size];

	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_data[i] = copy[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->_data != NULL)
	{
		delete[] this->_data;
	}
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
	if (this != &other)
	{
		delete[] this->_data;

		this->_size = other.size();
		this->_data = new T[this->_size];

		for (unsigned int i = 0; i < this->_size; i++)
		{
			this->_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[]( unsigned int index )
{
	if (index >= this->_size)
	{
		throw std::out_of_range("Index out of range");
	}
	return this->_data[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
	{
		throw std::out_of_range("Index out of range");
	}
	return this->_data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}
