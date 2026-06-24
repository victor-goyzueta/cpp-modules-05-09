#include "../inc/ScalarConverter.hpp"
#include "Convert.cpp"

#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert( const std::string& literal )
{
	LiteralType type = getType(literal);
	if (type == INVALID)
	{
		printInvalid();
		return;
	}
	double value = parseToDouble(literal, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
