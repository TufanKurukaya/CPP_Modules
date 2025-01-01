#include <iostream>

int main(int argc, char **argv)
{
	if (argc >= 2)
		for (int i = 1;argv[i]; i++)
			for (int j = 0;argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
