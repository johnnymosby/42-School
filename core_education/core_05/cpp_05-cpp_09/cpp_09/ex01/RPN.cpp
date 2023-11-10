#include "RPN.hpp"

static bool isoperand(char c) {
	return (c == '*' || c == '/' || c == '+' || c == '-');
}

static bool isValidCharacter(char c) {
	return (isdigit(c) || isoperand(c));
}

bool isValidInput(char const * expr) {
	while (*expr != '\0') {
		if (isspace(*expr))
			expr++;
		else if (!isValidCharacter(*expr))
			return false;
		else if (!(isspace(expr[1]) || expr[1] == '\0'))
			return false;
		else
			expr++;
	}
	return true;
}

static double apply_operand(char op, double a, double b) {
	switch (op) {
		case '*':
			return a * b;
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			if (fabs(b) < EPSILON) 
				throw std::runtime_error("Error: second operator cannot be equal to 0");
			else return a / b;
		default:
			throw std::runtime_error("Error: incorrect operand");
	}
}

bool calculate(char const * expr, double &answer) {
	std::stack<double> values;
	double a, b;

	while (*expr != '\0') {
		if (isoperand(*expr)) {
			if (values.size() < 2) {
				return false;
			} else {
				b = values.top();
				values.pop();
				a = values.top();
				values.pop();
				values.push(apply_operand(*expr, a, b));
			}
		}
		else if (isdigit(*expr)) {
			values.push(*expr - '0');
		}
		expr++;
	}
	if (values.size() != 1)
		return false;
	else {
		answer = values.top();
		return true;
	}
}
