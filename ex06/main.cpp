#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}
	Harl().complain(av[1]);
}
