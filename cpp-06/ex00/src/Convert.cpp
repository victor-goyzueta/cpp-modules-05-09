#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

enum LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID,
};

/*boolFuntions*/
static bool		isPseudoFloat(const std::string &s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff");	
}

static bool		isPseudoDouble(const std::string &s)
{
	return (s == "nan" || s == "+inf" || s == "-inf");
}

static bool		isCharLiteral(const std::string &s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
	//return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool		isIntLiteral(const std::string &s)
{
	if (s.empty())
		return false;
	size_t	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	return true;
}

static bool		isFloatLiteral(const std::string &s)
{
	if (s.empty() || s[s.length() - 1] != 'f')
		return false;
	
	std::string f = s.substr(0, s.length() - 1);
	if (f.empty())
		return false;
	bool	dotFound = false;
	size_t	i = 0;
	if (f[i] == '+' || f[i] == '-')
		i++;
	if (i == f.length())
		return false;
	while (i < f.length())
	{
		if (f[i] == '.')
		{
			if (dotFound)
				return false;
			dotFound = true;
		}
		else if (!std::isdigit(f[i]))
			return false;
		i++;
	}
	return dotFound;
}

static bool		isDoubleLiteral(const std::string &s)
{
	if (s.empty())
		return false;
	bool	dotFound = false;
	size_t	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length())
	{
		if (s[i] == '.')
		{
			if (dotFound)
				return false;
			dotFound = true;
		}
		else if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	return dotFound;
}

/*printFuntions*/
void	printChar( double value )
{
	std::cout << "char: ";
	if (value < 0 || value > 127
		|| std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char	c = static_cast<char>(value);
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	printInt( double value )
{
	std::cout << "int: ";
	if (value < INT_MIN || value > INT_MAX
		|| std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void	printFloat( double value )
{
	std::cout << "float: ";
	float	f = static_cast<float>(value);
	if (std::isnan(f))
	{
		std::cout << "nanf" << std::endl;
		return;
	}
	if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return;
	}
	std::cout << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void	printDouble( double value )
{
	std::cout << "double: ";
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
		return;
	}
	std::cout << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}

void	printInvalid( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

LiteralType getType( const std::string& literal )
{
	if (isPseudoFloat(literal))
		return PSEUDO_FLOAT;
	if (isPseudoDouble(literal))
		return PSEUDO_DOUBLE;
	if (isCharLiteral(literal))
		return CHAR;
	if (isIntLiteral(literal))
		return INT;
	if (isFloatLiteral(literal))
		return FLOAT;
	if (isDoubleLiteral(literal))
		return DOUBLE;
	return INVALID;
}

double	parseToDouble(const std::string &literal, LiteralType type)
{
	switch (type)
	{
		case CHAR:
			return static_cast<double>(literal[0]);
		case INT:
			return static_cast<double>(std::strtod(literal.c_str(), NULL));
		case FLOAT:
			return static_cast<double>(std::strtod(literal.c_str(), NULL));
		case DOUBLE:
			return std::atof(literal.c_str());
		case PSEUDO_FLOAT:
			if (literal == "nanf")
				return std::numeric_limits<float>::quiet_NaN();
			if (literal == "+inff")
				return std::numeric_limits<float>::infinity();
			return -std::numeric_limits<float>::infinity();
		case PSEUDO_DOUBLE:
			if (literal == "nan")
				return std::numeric_limits<double>::quiet_NaN();
			if (literal == "+inf")
				return std::numeric_limits<double>::infinity();
			return -std::numeric_limits<double>::infinity();
		default:
			return 0.0;
	}
}
