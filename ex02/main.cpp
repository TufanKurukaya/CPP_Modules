#include "PmergeMe.hpp"
#include <cstdlib>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		cout << "Usage: ./PmergeMe [Numbers]" << endl;
		return 1;
	}
	PmergeMe pm;
	string arg = av[1];
	try
	{
		if (ac == 2)
			checkArgs(arg, pm.nums);
		else
		{
			for (int i = 1; i < ac; i++)
			{
				arg = av[i];
				checkArgs(arg, pm.nums);
			}
		}
	}
	catch(const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		return 1;
	}
	try
	{
		size_t count = pm.nums.size();
		vector<int> vec(count);
		deque<int> deque(count);

		pm.firs_start = clock();
		for (size_t i = 0; i < count; i++)
			vec[i] = pm.nums[i];
		fordJhonson(vec, 0, vec.size() - 1);
		pm.first_end = clock();

		pm.second_start = clock();
		fordJhonson(deque, 0, deque.size() - 1);
		for (size_t i = 0; i < count; i++)
			deque[i] = pm.nums[i];
		pm.second_end = clock();
		cout << "How many numbers to print: ";
		int num = 0;
		cin >> num;
		cout << "Before sorting: ";
		PrintArr(pm.nums, num);
		cout << "After sorting: ";
		PrintArr(vec, num);
		cout << "Time to process a range of [" << count << "] elements with std::vector : " << std::fixed  << (double)(pm.first_end - pm.firs_start) / CLOCKS_PER_SEC << "s" << endl;
		cout << "Time to process a range of [" << count << "] elements with std::deque  : " << std::fixed  <<(double)(pm.second_end - pm.second_start) / CLOCKS_PER_SEC << "s" << endl;
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
