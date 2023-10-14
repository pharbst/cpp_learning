/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:14:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/15 01:26:00 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./RPN \"[expression]\"" << std::endl;
		return 1;
	}
	std::string	input = argv[1];
	std::cout << RPN::calculate(input) << std::endl;
	return 0;
}