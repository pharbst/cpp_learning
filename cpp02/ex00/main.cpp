/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:11 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 13:35:01 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed	a;
	std::cout << std::endl;
	Fixed	b(a);
	std::cout << std::endl;
	Fixed	c;
	std::cout << std::endl;

	c = b;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;
	return (0);
}