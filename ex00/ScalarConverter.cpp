#include "ScalarConverter.hpp"
#include <errno.h>
#include <float.h>
void ScalarConverter::convert(const string &input)
{
	if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
	{
		std::cout << "char: '" << static_cast<char>(input[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		return ;
	}
	if (!isValidFloat(input) && !isValidInt(input))
	{
		std::cout << "Invalide convert" << std::endl;
		return ;
	}
	long asInt = std::atol(input.c_str());

	if ((isValidInt(input) || isValidFloat(input)) && !(asInt > 127 || asInt < -128))
	{
		if (std::isprint(asInt))
			std::cout << "char: '" << static_cast<char>(asInt) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if ((isValidInt(input) || isValidFloat(input)) && !(asInt > std::numeric_limits<int>::max() || asInt < std::numeric_limits<int>::min()))
		std::cout << "int: " << static_cast<int>(asInt) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (isValidFloat(input))
	{
		float asFloat = std::strtof(input.c_str(), NULL);
		if (errno == ERANGE)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(asFloat) << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if (isValidFloat(input))
	{
		double asDouble = std::strtod(input.c_str(), NULL);
		if (errno == ERANGE)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "double: " << asDouble << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::isValidInt(const std::string &str)
{
		if (str.empty())
			return false;
		size_t i = 0;
		if (str[0] == '-' || str[0] == '+')
			i = 1;
		for (; i < str.length(); ++i)
			if (!std::isdigit(str[i]))
				return false;
		return true;
}

bool ScalarConverter::isValidFloat(const std::string &str)
{
	char *endPtr;
	double inf_or_nan = std::strtod(str.c_str(), &endPtr);
	if (std::isinf(inf_or_nan) || std::isnan(inf_or_nan))
	{
		if (endPtr != str.c_str() && (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0')))
			return true;
	}
	return endPtr != str.c_str() && (*endPtr == '\0' || ((*endPtr == 'f' && *(endPtr + 1) == '\0')));
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this != &src)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
