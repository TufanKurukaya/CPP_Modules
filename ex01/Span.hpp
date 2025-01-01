#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int n);
		void addNumber(int n , int m);
		int shortestSpan();
		int longestSpan();
		class NoValueException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};




#endif
