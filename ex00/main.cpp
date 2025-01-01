#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try {
		std::cout << *easyfind(v, 5) << std::endl;
		std::vector<int>::iterator it = easyfind(v, 3);
		*it = 10;
		std::cout << *easyfind(v, 10) << std::endl;
		std::cout << *easyfind(v, 3) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}
	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	try {
		std::cout << *easyfind(l, 3) << std::endl;
		std::cout << *easyfind(l, 99) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}
	return 0;
}
