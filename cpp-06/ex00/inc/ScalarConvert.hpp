#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cctype>
# include <cmath>

class ScalarConvert
{
	private:
		ScalarConvert();
		ScalarConvert( const ScalarConvert& copy );
		~ScalarConvert();
		
		ScalarConvert& operator=( const ScalarConvert& other );
	
	public:
		static void	convert( std::string& literal );
};

#endif
