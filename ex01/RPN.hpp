#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <set>
#include <errno.h>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::istringstream;
using std::set;

float evaluateExpression(const std::string& expression);
bool isOperator(char c);
float performOperation(float a, float b, char op);

#endif // RPN_HPP
