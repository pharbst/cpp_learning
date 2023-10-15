/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 04:15:01 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/09 11:16:00 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::map<std::string, double>	BitcoinExchange::_database;

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src)
		*this = src;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

const char* BitcoinExchange::FileNotFoundException::what() const throw() {
	return "Could not open database check path and try again.";
}

const char*	BitcoinExchange::InvalidDatabaseException::what() const throw() {
	return "Invalid Format in database or empty database.";
}

std::string	BitcoinExchange::extractDate(const std::string& line) {
	size_t	commaPosition = line.find(',');
	if (commaPosition == std::string::npos)
		throw InvalidDatabaseException();
	std::string dateString = line.substr(0, commaPosition);
	return dateString;
}

double	BitcoinExchange::extractExchangeRate(const std::string& line) {
	size_t	commaPosition = line.find(',');
	if (commaPosition == std::string::npos)
		throw InvalidDatabaseException();
	std::string	exchangeRateString = line.substr(commaPosition + 1);
	double	ret = strtod(exchangeRateString.c_str(), NULL);
	return ret;
}

void	BitcoinExchange::init(std::string database) {
	std::ifstream	file(database.c_str());
	if (!file.is_open())
		throw FileNotFoundException();
	for (std::string line; std::getline(file, line);) {
		try {
			_database.insert(std::pair<std::string, double>(extractDate(line), extractExchangeRate(line)));
		}
		catch(const std::exception& e) {
			file.close();
			throw InvalidDatabaseException();
			return ;
		}
	}
	file.close();
	if (_database.empty())
		throw InvalidDatabaseException();
}

double	BitcoinExchange::getExchangeRate(std::string date, double amount) {
	std::map<std::string, double>::iterator	it = _database.lower_bound(date);
	if (it->first == date)
		return it->second * amount;
	else if (it == _database.begin())
		throw InvalidDatabaseException();
	else
		--it;
	return it->second * amount;
}
