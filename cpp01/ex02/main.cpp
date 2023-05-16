/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:30:39 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 13:53:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "address of string:         " << &string << std::endl;
	std::cout << "address of stringPTR:      " << &stringPTR << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address of stringREF:      " << &stringREF << std::endl;
	std::cout << "value of string:           " << string << std::endl;
	std::cout << "value of stringPTR:        " << *stringPTR << std::endl;
	std::cout << "value of stringREF:        " << stringREF << std::endl;
	return (0);
}
