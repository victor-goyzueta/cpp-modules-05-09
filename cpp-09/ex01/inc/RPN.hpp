#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
# include <exception>
# include <stdexcept>


class RPN
{
	private:
		std::stack<int>		_stack;
		bool	isOperator( const std::string& token ) const;
		void	applyOperation( const std::string& op );

	public:
		RPN();
		RPN( const RPN& other );
		~RPN();

		RPN&	operator=( const RPN& other );

		void	evaluate( const std::string& expression );
};

#endif
