#include "BitcoinExchange.hpp"

string removWhiteSpac(const string &str) {
	string  res = "";

	size_t start = str.find_first_not_of(" \n\r\t\f\v");
	if (start != string::npos)
		res = str.substr(start);

	size_t end = res.find_last_not_of(" \n\r\t\f\v");
	if (end != string::npos)
		res = res.substr(0, end + 1);
	return res;
}

void isValidDate(const string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		throw std::invalid_argument(" => Bad Date!");
	}
	for (size_t i = 0; date[i]; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			throw std::invalid_argument(" => Bad Date!");
	}
	
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12) {
		throw std::invalid_argument(" => Bad month");
	}

	if (day < 1 || day > 31) {
		throw std::invalid_argument(" => Bad day");
	}

	std::tm tm = {};
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;

	tm.tm_isdst = -1;
	std::time_t time = std::mktime(&tm);

	if (!(time != -1 && tm.tm_year + 1900 == year && tm.tm_mon + 1 == month && tm.tm_mday == day))
		throw std::invalid_argument(" => Bad Date!");
}

bool BitcoinExchange::isValidInt(const string &str)
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

bool BitcoinExchange::isValidFloat(const string &str)
{
	char *endPtr;
	double value = std::strtod(str.c_str(), &endPtr);
	if (errno == ERANGE)
		return false;
	if (std::isinf(value) || std::isnan(value))
		return false;
	return endPtr != str.c_str() && (*endPtr == '\0' || ((*endPtr == 'f' && *(endPtr + 1) == '\0')));
}

double BitcoinExchange::Converter(const string &str)
{
	if (!isValidFloat(str) && !isValidInt(str))
		throw std::invalid_argument(" => Bad Input Value");
	return std::strtod(str.c_str(),NULL);
}
void BitcoinExchange::btc_converter(string const &date ,double const &value)
{
	std::map<string, double>::iterator it =_bitcoinValues.lower_bound(date);
	if (it == _bitcoinValues.end() || it->first != date)
	{
		if (it == _bitcoinValues.begin() || it == _bitcoinValues.end())
			throw std::invalid_argument(" => No data");
		--it;

	}
	double res = value * it->second;
	cout << date << " => " << std::fixed << std::setprecision(2) << res << " BTC" << endl;
}
void BitcoinExchange::btc(ifstream &inputFile)
{
	string line;
	getline(inputFile, line);
	if (line != "date | value")
		throw std::invalid_argument("Input file Not date | value");
	size_t pos;
	try
	{
		while (getline(inputFile, line))
		{
			string first;
			string second;

			pos = line.find("|");
			if (pos != string::npos)
			{
				try
				{
					first = removWhiteSpac(line.substr(0 ,pos));
					second = removWhiteSpac(line.substr(pos + 1));
					isValidDate(first);
					double value = Converter(second);
					if (value < 0)
						throw std::invalid_argument(" => Value can't be negative");
					if (value > 1000)
						throw std::invalid_argument(" => Value can't be greater than 1000");
					btc_converter(first, value);
					first.clear();
				}
				catch(const std::exception& e)
				{
					if (!first.empty())
						cout << first << e.what() << '\n';
					else
						cout << "Erorr :" << e.what() << '\n';
				}
			}
			else if (!line.empty())
				cout << "Error => Line is empty" << endl;
			else
				cout << "Error bad input => " << line << endl;
		}
	}
	catch(const std::exception& e)
	{
		if (!_data.eof() || !inputFile.eof())
			throw;
	}
}

BitcoinExchange::BitcoinExchange()
{
	_data.exceptions(ifstream::badbit | ifstream::failbit);
	_data.open("data.csv");
	string line;
	std::size_t pos;
	getline(_data, line);
	try
	{
		while (getline(_data, line))
		{
			string first;
			string second;

			pos = line.find(',');
			if (pos != string::npos)
			{
				try
				{
					first = removWhiteSpac(line.substr(0 ,pos));
					second = removWhiteSpac(line.substr(pos + 1));
					_bitcoinValues[first] = Converter(second);
				}
				catch(const std::exception& e)
				{
					cout << "Invalide line data.csv " << e.what() << '\n';
				}
			}
		}
	}
	catch(const std::exception& e)
	{
		if (!_data.eof())
			throw;
	}

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	_data.exceptions(ifstream::failbit | ifstream::badbit);
	_data.open("data.csv");
	BitcoinExchange::operator=(src);
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	_bitcoinValues = src._bitcoinValues;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

