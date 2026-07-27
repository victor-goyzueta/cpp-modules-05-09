#include "../inc/BitcoinExchange.hpp"

# include <iostream>
# include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy )
{
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDatabase( const std::string &filename )
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	std::getline(file, line);
	if (!line.c_str())
		throw std::runtime_error("Empty file");
	while (std::getline(file, line))
	{
		std::string	date, priceStr;
		double		price;

		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		date = line.substr(0, pos);
		std::string priceStr = line.substr(pos + 1);

		char *end;
		price = std::strtod(priceStr.c_str(), &end);
		if (!(*end != '\0' && *end != '\n' && *end != '\r'))
			_database[date] = price;
	}
	file.close();
}

void	BitcoinExchange::processInput( const std::string &filename )
{
	//
}
