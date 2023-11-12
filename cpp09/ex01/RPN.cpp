/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:14:35 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/12 06:10:18 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_stack;

RPN::RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &src) {
	if (this != &src) {
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

const char* RPN::InvalidExpressionException::what() const throw() {
	return "Invalid expression.";
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero.";
}

const char* RPN::StackNotEmptyException::what() const throw() {
	return "Stack not empty after calculation.";
}

int	RPN::calculate(std::string input) {
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token) {
		if ((!isOperator(token) && !std::isdigit(token[0])) || token.length() > 1)
			throw RPN::InvalidExpressionException();
		else if (!isOperator(token)) {
			_stack.push(std::atoi(token.c_str()));
		}
		else {
			if (_stack.size() < 2)
				throw RPN::InvalidExpressionException();
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/") {
				if (a == 0)
					throw RPN::DivisionByZeroException();
				_stack.push(a / b);
			}
		}
	}
	if (_stack.size() != 1)
		throw RPN::StackNotEmptyException();
	double result = _stack.top();
	_stack.pop();
	return result;
}

bool	RPN::isOperator(std::string token) {
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return true;
	return false;
}
