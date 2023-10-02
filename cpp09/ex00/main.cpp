/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:15:59 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/02 07:43:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	ExtractDate(const std::string& line) {
	size_t	commaPosition = line.find(',');
	if (commaPosition == std::string::npos)
		return -1;
	std::string	dateString = line.substr(0, commaPosition);
	dateString.erase(std::remove(dateString.begin(), dateString.end(), '-'), dateString.end());
	return std::stoi(dateString);
}

class InvalidArgumentsException : public std::exception {
	virtual const char* what() const throw() {
		return "Invalid or no path to inputfile given.";
	}
};

int main(int argc, char **argv) {
	if (argc != 2)
		throw InvalidArgumentsException();
	try {
		BitcoinExchange::init(argv[1]);
		std::fstream	inputFile(argv[1]);
		if (!inputFile.is_open())
			throw InvalidArgumentsException();
		for (std::string line; std::getline(inputFile, line);) {
			try {
				int		date = ExtractDate(line);
				double	amount = std::stod(line.substr(line.find(',') + 1));
				std::cout << "Date: " << date << " Amount: " << amount << " Exchange Value: " << BitcoinExchange::getExchangeRate(date, amount) << std::endl;
			}
			catch(std::exception& e) {
				(void)e;
			}
		}
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
