/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/15 02:47:59 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void){
	std::cout << "Default constructer called" << std::endl;
	FixedPoint = 0;
}

Fixed::Fixed(int const raw){
	std::cout << "Int constructer called" << std::endl;
	FixedPoint = raw;
}

Fixed::Fixed(float const raw) : FixedPoint(roundf(raw * (1 << NumberOfBits))){
	std::cout << "Float constructer called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructer called" << std::endl;
	this->FixedPoint = copy.FixedPoint;
}

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		FixedPoint = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Default deconstructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return FixedPoint;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	FixedPoint = raw;
}

int	Fixed::toInt() const{
	return FixedPoint >> NumberOfBits;
}

float	Fixed::toFloat() const{
	return static_cast<float>(FixedPoint / static_cast<float>(1 << NumberOfBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& src){
	os << src.toFloat();
	return os;
}
