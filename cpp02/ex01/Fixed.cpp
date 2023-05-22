/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 13:45:26 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _FixedPoint(0){
	std::cout << "\033[1;32mDefault constructer called\033[0m" << std::endl;
}

Fixed::Fixed(int const raw) : _FixedPoint(raw << NumberOfBits){
	std::cout << "\033[1;32mInt constructer called\033[0m" << std::endl;
}

Fixed::Fixed(float const raw) : _FixedPoint(roundf(raw * (1 << NumberOfBits))){
	std::cout << "\033[1;32mFloat constructer called\033[0m" << std::endl;
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

int	Fixed::toInt() const{
	return _FixedPoint >> NumberOfBits;
}

float	Fixed::toFloat() const{
	return static_cast<float>(_FixedPoint / static_cast<float>(1 << NumberOfBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& src){
	os << src.toFloat();
	return os;
}
