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
		
		void	addNumber( int number );

		template <typename Iterator>
		void	addRange( Iterator begin, Iterator end )
		{
			unsigned int	distance = std::distance(begin, end);
			if (_numbers.size() + distance > _maxSize)
				throw std::runtime_error("Cannot add range: Span will overflow");
			_numbers.insert(_numbers.end(), begin, end);
		}

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		void			printNumbers() const;
};

#endif
