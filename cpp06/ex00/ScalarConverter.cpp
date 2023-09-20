/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:35:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/20 14:46:10 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
			_double(strtod(input.c_str(), NULL));
		}
		catch (std::exception &e) {
			std::cout << "invalid input" << std::endl;
			return ;
		}
	}
	else {
		for (int i = 0; input[i]; i++) {
			if (!isdigit(input[i]) && input[i] != '-') {
				std::cout << "invalid input" << std::endl;
				return ;
			}
		}
		_int(atol(input.c_str()));
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
	if (_float == static_cast<int>(c))
		std::cout << "float: " << _float << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;
	if (_double == static_cast<int>(c))
		std::cout << "double: " << _double << ".0" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_int(long i) {
	char	_char;
	float	_float;
	double	_double;

	_char = static_cast<char>(i);
	_float = static_cast<float>(i);
	_double = static_cast<double>(i);
	
	if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else if (i < 0 || i > 255)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i < INT_MIN || i > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (_float == static_cast<int>(i))
		std::cout << "float: " << _float << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;
	if (_double == static_cast<int>(i))
		std::cout << "double: " << _double << ".0" << "f" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_float(float f) {
	char	_char;
	int		_int;
	double	_double;

	_char = static_cast<char>(f);
	_int = static_cast<int>(f);
	_double = static_cast<double>(f);
	
	if (isnan(f) || isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else if (_int < 0 || _int > 255)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (isnan(f) || isinf(f))
		std::cout << "int: impossible" << std::endl;
	else if (f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	if (f == static_cast<int>(f))
		std::cout << "float: " << f << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (_double == static_cast<int>(f))
		std::cout << "double: " << _double << ".0" << std::endl;
	else
		std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_double(double d) {
	char	_char = static_cast<char>(d);
	int		_int = static_cast<int>(d);
	float	_float = static_cast<float>(d);

	if (isnan(d) || isinf(d) || _int < 0 || _int > 255)
		std::cout << "char: impossible" << std::endl;
	else if (_char < 126 && _char > 32)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (isnan(d) || isinf(d))
		std::cout << "int: impossible" << std::endl;
	else if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	if (_float == static_cast<int>(d))
		std::cout << "float: " << _float << ".0" << "f" << std::endl;
	else
		std::cout << "float: " << _float << "f" << std::endl;
	if (d == static_cast<int>(d))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
