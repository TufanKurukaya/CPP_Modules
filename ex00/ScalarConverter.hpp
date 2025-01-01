#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

class ScalarConverter
{
	private:
		static bool isValidInt(const std::string& str);
		static bool isValidFloat(const std::string& str);
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter &operator=(ScalarConverter const &);
		~ScalarConverter();
	public:
		static void convert(const string &input);
};



#endif
