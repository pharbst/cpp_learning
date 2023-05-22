/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 13:33:24 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FixedPoint(0){
	std::cout << "\033[1;32mDefault constructer called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _FixedPoint(copy._FixedPoint){
	std::cout << "\033[1;32mCopy constructer called\033[0m" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "\033[1;32mCopy assignment operator called\033[0m" << std::endl;
	if (this != &src)
		_FixedPoint = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "\033[1;31mDefault deconstructor called\033[0m" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "\033[0;33mgetRawBits member function called\033[0m" << std::endl;
	return _FixedPoint;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "\033[0;33msetRawBits member function called\033[0m" << std::endl;
	_FixedPoint = raw;
}
