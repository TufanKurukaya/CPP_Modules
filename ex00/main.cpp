#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
	if (ac != 2)
	{
		cout << "Usage: ./btc <Input File>" << endl;
		return 1;
	}
	ifstream inputFile;
	try
	{
		inputFile.exceptions(ifstream::failbit | ifstream::badbit);
		inputFile.open(av[1]);
		BitcoinExchange().btc(inputFile);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}

}
