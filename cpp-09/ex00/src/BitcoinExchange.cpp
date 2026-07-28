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

void	BitcoinExchange::loadDataBase( const std::string &filename )
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");

	std::getline(file, line);

	if (!line.c_str())
		throw std::runtime_error("Error: empty file");

	while (std::getline(file, line))
	{
		std::string	date, priceStr;
		double		price;

		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		date = line.substr(0, pos);
		priceStr = line.substr(pos + 1);

		char *end;
		price = std::strtod(priceStr.c_str(), &end);
		if (!(*end != '\0' && *end != '\n' && *end != '\r'))
			_database[date] = price;
	}
	file.close();
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return (year % 4 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year =	std::atoi(date.substr(0, 4).c_str());
    int month =	std::atoi(date.substr(5, 2).c_str());
    int day =	std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(double value)const
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

double BitcoinExchange::getPrice(const std::string &date) const
{
    if (_database.empty())
        return -1;
    std::map<std::string, double>::const_iterator it = _database.find(date);
    if (it != _database.end())
    {
        return it->second;
    }
    it = _database.lower_bound(date); // busca el primer eemento >= date
    if (it == _database.begin()) // no hay fecha anterior, ERROR.
        return -1;
    it--;
    return it->second;
}

void BitcoinExchange::calculateAndDisplay(const std::string &date, double value)const
{
    double price = getPrice(date);

    if (price < 0)
    {
        std::cerr << "Error: no price data available for date." << std::endl;
        return;
    }

    double result = value * price;

    std::cout << date << " => " << value << " = " << result << std::endl;
}

void	BitcoinExchange::processInput( const std::string &filename )
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");

	std::getline(file, line);

	if (!line.c_str())
		throw std::runtime_error("Error: empty file");

	while (std::getline(file, line))
    {
        std::string	date;
        double 		value;
        
		size_t position = line.find(" | ");
		if (position == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
            continue;
		}
		date = line.substr(0, position);
		std::string valueStr = line.substr(position + 3);
		
		char *end;
		value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0' && *end != '\n' && *end != '\r')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
            continue;
		}

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input =>" << date  <<  std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number " << std::endl;
            continue;
        }

        if (!isValidValue(value))
        {
            std::cerr << "Error: too large a number " << std::endl;
            continue;
        }
        calculateAndDisplay(date, value);
    }
    file.close();
}
