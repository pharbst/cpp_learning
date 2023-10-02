/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 04:14:32 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/02 06:24:19 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange {
	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);
		~BitcoinExchange(void);

		static std::map<int, double>	_database;

		static int		extractDate(const std::string& line);
		static double	extractExchangeRate(const std::string& line);

		class	FileNotFoundException : public std::exception {
			virtual const char* what() const throw();
		};

		class	InvalidDatabaseException : public std::exception {
			virtual const char* what() const throw();
		};

	public:
		static void		init(std::string database);
		static double	getExchangeRate(int date, double amount);
};

#endif