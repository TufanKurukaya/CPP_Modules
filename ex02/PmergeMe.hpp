#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::deque;
using std::clock_t;
using std::string;
using std::istringstream;

struct PmergeMe
{
	clock_t firs_start, first_end;
	clock_t second_start, second_end;
	vector<int> nums;
};

void checkArgs(string &arg, vector<int> &nums);

#include "PmergeMe.tpp"

#endif // PMERGEME_HPP
