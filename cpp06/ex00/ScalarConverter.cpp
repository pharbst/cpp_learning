/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:35:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/19 15:57:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input) {
	if (input == "nan")
		_double(std::numeric_limits<double>::quiet_NaN());
	else if (input == "nanf")
		_float(std::numeric_limits<float>::quiet_NaN());
	else if (input == "-inf")
		_double(-std::numeric_limits<double>::infinity());
	else if (input == "-inff")
		_float(-std::numeric_limits<float>::infinity());
	else if (input == "+inf")
		_double(std::numeric_limits<double>::infinity());
	else if (input == "+inff")
		_float(std::numeric_limits<float>::infinity());
	else if (input.length() == 1 && !std::isdigit(input[0]))
		_char(input[0]);
	else if (input[input.length() - 1] == 'f') {
		try {
			_float(strtof(input.c_str(), NULL));
		}
		catch (std::exception &e) {
			std::cout << "invalid input" << std::endl;
			return ;
		}
	}
	else {
		for (int i = 0; input[i]; i++) {
			if (!isdigit(input[i])) {
				std::cout << "invalid input" << std::endl;
				return ;
			}
		}
		_int(atoi(input.c_str()));
	}
}

void	ScalarConverter::_char(char c) {
	int		_int;
	float	_float;
	double	_double;

	_int = static_cast<int>(c);
	_float = static_cast<float>(c);
	_double = static_cast<double>(c);
	
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_int(int i) {
	char	_char;
	float	_float;
	double	_double;

	_char = static_cast<char>(i);
	_float = static_cast<float>(i);
	_double = static_cast<double>(i);
	
	if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_float(float f) {
	char	_char;
	int		_int;
	double	_double;

	_char = static_cast<char>(f);
	_int = static_cast<int>(f);
	_double = static_cast<double>(f);
	
	if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_double(double d) {
	char	_char;
	int		_int;
	float	_float;

	_char = static_cast<char>(d);
	_int = static_cast<int>(d);
	_float = static_cast<float>(d);
	
	if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
