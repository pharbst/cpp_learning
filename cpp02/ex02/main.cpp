/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 07:12:03 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 14:15:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void){
	Fixed	a;
	std::cout << "\033[1;35mdeclared a\033[0m" << std::endl;
	Fixed	b(42.42f);
	std::cout << "\033[1;35mdeclared b with value 42.42\033[0m" << std::endl;
	Fixed	c;
	std::cout << "\033[1;35mdeclared c\033[0m" << std::endl;
	a = (Fixed(1234.4321f));
	std::cout << "\033[1;35ma = Fixed(1234.4321)\033[0m" << std::endl;

	c = a;
	std::cout << "\033[1;35mc = a\033[0m" << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "\033[1;35mPrinted a, b and c\033[0m" << std::endl;

	if (a < b)
		std::cout << "\033[1;35ma < b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !< b\033[0m" << std::endl;
	if (a > b)
		std::cout << "\033[1;35ma > b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !> b\033[0m" << std::endl;
	if (a == b)
		std::cout << "\033[1;35ma == b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !== b\033[0m" << std::endl;
	if (a != b)
		std::cout << "\033[1;35ma != b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !!= b\033[0m" << std::endl;
	if (a <= b)
		std::cout << "\033[1;35ma <= b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !<= b\033[0m" << std::endl;
	if (a >= b)
		std::cout << "\033[1;35ma >= b\033[0m" << std::endl;
	else
		std::cout << "\033[1;35ma !>= b\033[0m" << std::endl;
	std::cout << "\033[1;35mPerformed all compare operators\033[0m" << std::endl;

	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << "\033[1;35mused ++a 19 times\033[0m" << std::endl;

	a = 0;
	std::cout << "\033[1;35ma = 0\033[0m" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a++ << std::endl;

	std::cout << "\033[1;35mused a++ 19 times\033[0m" << std::endl;
	
	a = 0;
	std::cout << "\033[1;35ma = 0\033[0m" << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;

	std::cout << "\033[1;35mused --a 19 times\033[0m" << std::endl;
	
	a = 0;
	std::cout << "\033[1;35ma = 0\033[0m" << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;

	std::cout << "\033[1;35mused a-- 19 times\033[0m" << std::endl;

	Fixed	d;

	d = Fixed::min(a, b);
	std::cout << "\033[1;35mget the smallest value of a and b\033[0m" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "\033[1;35mthe smallest is \033[0m" << d << std::endl;

	d = Fixed::max(a, b);
	std::cout << "\033[1;35mget the biggest value of a and b\033[0m" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "\033[1;35mthe biggest is \033[0m" << d << std::endl;

	std::cout << "\033[1;35mSome bonus features\033[0m" << std::endl;
	c = 4242;
	std::cout << "\033[1;35mc = 4242\033[0m" << std::endl;
	std::cout << c << std::endl;
	std::cout << "\033[1;35mPrinted c\033[0m" << std::endl;
	c = 42.4242f;
	std::cout << "\033[1;35mc = 42.4242f\033[0m" << std::endl;
	std::cout << c << std::endl;
	std::cout << "\033[1;35mPrinted c\033[0m" << std::endl;

	c = 123.321f;
	std::cout << "\033[1;35mc = 123.321f\033[0m" << std::endl;
	d = c / Fixed(0);
	std::cout << "\033[1;35md = c / Fixed(0)\033[0m" << std::endl;
	return 0;
}
