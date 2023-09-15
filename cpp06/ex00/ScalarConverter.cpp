/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:35:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/15 18:22:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input) {
	if (input == "nan" || input == "nanf")
		_nan = true;
	else if (input == "-inf" || input == "-inff")
		_neg_inf = true;
	else if (input == "+inf" || input == "+inff")
		_inf = true;
	else if (input.length() == 1)
		_char = input[0];
	else {
		try {
			_int = std::stoi(input);
		}
		catch (std::exception &e) {
			std::cout << "int: impossible" << std::endl;
		}
		try {
			_float = std::stof(input);
		}
		catch (std::exception &e) {
			std::cout << "float: impossible" << std::endl;
		}
		try {
			_double = std::stod(input);
		}
		catch (std::exception &e) {
			std::cout << "double: impossible" << std::endl;
		}
	}
}
