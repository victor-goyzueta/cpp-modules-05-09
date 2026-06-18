#include "Span.hpp"

Span::Span(): _maxSize(0) {}

Span::Span( unsigned int n ): _maxSize(n) {}

Span::Span( const Span& copy ):
	_maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span& Span::operator=( const Span& other )
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber( int number )
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Cannot add number: Span is full");
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan() const
{
	if  (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < tmp.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	int	minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int	maxValue = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(maxValue - minValue);
}

void	Span::printNumbers() const
{
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}
