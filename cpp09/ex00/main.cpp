/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:15:59 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/20 10:14:17 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>

class InvalidArgumentsException;

bool	init(int argc, std::string& database);
std::string	extractDate(const std::string& line);
bool	checkDate(std::string& date);
double	extractAmount(std::string& line);

int main(int argc, char **argv) {
	std::string	database = "./data.csv";
	// init
	(void)argv;
	if (init(argc, database))
		return 1;

	// open inputfile
	std::ifstream	inputFile(argv[1]);
	if (!inputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	// main logic
	std::cout << "date   |   value" << std::endl;
	for (std::string line; std::getline(inputFile, line);) {
		if (line == "Date | Value")
			continue;
		std::string	tmp = extractDate(line);
		double	amount	= extractAmount(line);
		if (tmp.empty())
			std::cout << "Error: Bad input => " << line << std::endl;
		else if (checkDate(tmp))
			std::cout << "Error: impossible date. => " << tmp << std::endl;
		else if (amount != -1) {
			try {
				std::cout << tmp << " => " << amount << " = " << BitcoinExchange::getExchangeRate(tmp, static_cast<double>(amount)) << std::endl; 
			}
			catch(std::exception& e){
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
}

bool	init(int argc, std::string& database) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange::init(database);
	}
	catch(std::exception& e) {
		std::cout << "Error in databe: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

std::string	extractDate(const std::string& line) {
	size_t	commaPosition = line.find('|');
	if (commaPosition == std::string::npos)
		return "";
	std::string dateString = line.substr(0, commaPosition - 1);
	return dateString;
}

bool	checkDate(std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return true;
	int	year = std::atoi(date.substr(0, 3).c_str());
	int	month = std::atoi(date.substr(5, 6).c_str());
	int	day = std::atoi(date.substr(8, 9).c_str());

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		return true;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return true;
	else if (year % 4 == 0 && month == 2 && day > 29)
		return true;
	else if (month == 2 && day > 28)
		return true;
	return false;
}

double	extractAmount(std::string& line) {
	size_t	commaPosi = line.find('|');
	if (commaPosi == std::string::npos)
		return -1;
	std::string tmp = line.substr(commaPosi + 1);
	double amount = std::atof(tmp.c_str());
	if (amount > INT_MAX) {
		std::cout << "Error: too large a number." << std::endl;
		return -1;
	}
	else if (amount < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return -1;
	}
	return amount;
}

class InvalidArgumentException : public std::exception {
	virtual const char* what() const throw() {
		return "Invalid or no path to inputfile given.";
	}
};
