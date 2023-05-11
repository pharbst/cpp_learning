/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:03:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/11 07:12:50 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "\033[1;33mHarl complains on debug level\033[0;32m" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\033[1;33mHarl complains on info level\033[0;32m" << std::endl;
	harl.complain("INFO");
	std::cout << "\033[1;33mHarl complains on warning level\033[0;32m" << std::endl;
	harl.complain("WARNING");
	std::cout << "\033[1;33mHarl complains on error level\033[0;32m" << std::endl;
	harl.complain("ERROR");
	std::cout << "\033[1;33mHarl complains on wrong level\033[1;31m" << std::endl;
	harl.complain("WRONG");
	return (0);
}