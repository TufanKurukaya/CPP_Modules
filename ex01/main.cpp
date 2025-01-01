#include "iter.hpp"

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArr[] = {"one", "two", "three", "four", "five"};

	std::cout << "Int array:" << std::endl;
	iter(intArr, 5, print);
	std::cout << "Float array:" << std::endl;
	iter(floatArr, 5, print);
	std::cout << "String array:" << std::endl;
	iter(stringArr, 5, print);
	return 0;
}
