#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange( const BitcoinExchange& copy );
		BitcoinExchange& operator=( const BitcoinExchange& other );

		std::map<std::string, double>	_database;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void loadDatabase( const std::string &filename );
        void processInput( const std::string &filename );
};

#endif
