/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:35:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/15 21:11:11 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input) {
	if (input == "nan")
		_double = std::numeric_limits<double>::quiet_NaN();
	else if (input == "nanf")
		_float = std::numeric_limits<float>::quiet_NaN();
	else if (input == "-inf")
		_double = -std::numeric_limits<double>::infinity();
	else if (input == "-inff")
		_float = -std::numeric_limits<float>::infinity();
	else if (input == "+inf")
		_double = std::numeric_limits<double>::infinity();
	else if (input == "+inff")
		_float = std::numeric_limits<float>::infinity();
	else if (input.length() == 1 && !std::isdigit(input[0]))
		_char = input[0];
	else if (input[input.length()] == 'f') {
		try {
			_float = std::stof(input);
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
	}
	// if (input == "nan" || input == "nanf")
	// 	_nan = true;
	// else if (input == "-inf" || input == "-inff")
	// 	_neg_inf = true;
	// else if (input == "+inf" || input == "+inff")
	// 	_inf = true;
	// else if (input.length() == 1)
	// 	_char = input[0];
	// else {
	// 	try {
	// 		_int = std::stoi(input);
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << "int: impossible" << std::endl;
	// 	}
	// 	try {
	// 		_float = std::stof(input);
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << "float: impossible" << std::endl;
	// 	}
	// 	try {
	// 		_double = std::stod(input);
	// 	}
	// 	catch (std::exception &e) {
	// 		std::cout << "double: impossible" << std::endl;
	// 	}
	// }
}
