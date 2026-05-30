#include <iostream>

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	if (this->content != NULL) {
		delete[] this->content;
	}
}

template <typename T>
Array<T>::Array()
{
	this->content = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->content = new T[size]();
	this->_size = size;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	this->_size = copy.size();
	this->content = new T[this->_size];

	for (unsigned int i = 0; i < this->_size; i++) {
		this->content[i] = copy[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	delete this->content;

	this->_size = other.size();
	this->content = new T[this->_size];
}


template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size) {
		throw std::out_of_range("Index out of range");
	}
	return this->content[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}
