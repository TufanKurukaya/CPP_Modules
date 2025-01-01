#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class BitcoinExchange
{
	private:
		ifstream _data;
		std::map<string, double> _bitcoinValues;
	public:
		bool isValidInt(const string &);
		bool isValidFloat(const string &);
		double Converter(const string &);
		void btc(ifstream &inputFile);
		void btc_converter(string const &date ,double const &value);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(const BitcoinExchange &);
		~BitcoinExchange();
};

#endif // BITCOINEXCHANGE_HPP
