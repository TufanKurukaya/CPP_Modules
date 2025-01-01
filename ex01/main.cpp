#include "RPN.hpp"

int main(int ac , char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}
	try
	{
		std::string expression = av[1];
		std::cout << evaluateExpression(expression) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
