#include "RPN.hpp"

float evaluateExpression(const std::string &expression)
{
	string validChars = "0123456789.+-*/ ";
	set<char> validSet(validChars.begin(), validChars.end());
	char *endPtr;
	for (string::const_iterator it =  expression.begin(); it != expression.end(); ++it)
	{
		if (validSet.find(*it) == validSet.end())
			throw std::invalid_argument("Error");
	}
	istringstream iss(expression);
	stack<float> stack;
	string token;
	while (iss >> token)
	{
		if (isOperator(token[0]))
		{
			float a = stack.top();
			stack.pop();
			float b = stack.top();
			stack.pop();
			stack.push(performOperation(b, a, token[0]));
		}
		else
		{
			float value = strtod(token.c_str(), &endPtr);
			if (errno == ERANGE || *endPtr != '\0' || (value < 0 || value >= 10))
				throw std::invalid_argument("Error");
			stack.push(value);
		}
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Error");
	return stack.top();
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

float performOperation(float a, float b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
	return 0;
}
