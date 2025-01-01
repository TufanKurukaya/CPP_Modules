#include "PmergeMe.hpp"

void checkArgs(string &arg, vector<int> &nums)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!isdigit(arg[i]) && arg[i] != ' ')
			throw std::invalid_argument("Error");
	}
	istringstream iss(arg);
	while (iss)
	{
		int temp;
		iss >> temp;
		if (iss)
			nums.push_back(temp);
	}
}
