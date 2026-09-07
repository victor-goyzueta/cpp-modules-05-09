#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
	private:
		BitcoinExchange( const BitcoinExchange& copy );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		
		std::map<std::string, double>	_database;
		
		bool	isValidDate( const std::string& date ) const;
		bool	isLeapYear( int year ) const;
		bool	isValidValue( double value ) const;

		void	calculateAndDisplay( const std::string& date, double value ) const;

		double	getPrice( const std::string& date ) const;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void loadDataBase( const std::string &filename );
        void processInput( const std::string &filename );
};

#endif
