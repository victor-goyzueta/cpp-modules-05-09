#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <climits>
# include <iterator>
# include <algorithm>
# include <vector>
# include <stdexcept>
# include <exception>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span( unsigned int n );
		Span( const Span& copy );
		~Span();

		Span& operator=( const Span& other );

		std::vector<int>	getNumbers() const;
		
		void	addNumber( int number );
		void	addRange( const std::vector<int> vec );

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif
