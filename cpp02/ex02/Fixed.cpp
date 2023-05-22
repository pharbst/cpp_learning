/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 14:22:06 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/**************************************************************/
/*                     Constructors                           */
/**************************************************************/

Fixed::Fixed(void) : _FixedPoint(0){
	std::cout << "\033[0;32mDefault constructer called\033[0m" << std::endl;
}

Fixed::Fixed(int const raw) : _FixedPoint(raw << NumberOfBits){
	std::cout << "\033[0;32mInt constructer called\033[0m" << std::endl;
}

Fixed::Fixed(float const raw) : _FixedPoint(roundf(raw * (1 << NumberOfBits))){
	std::cout << "\033[0;32mFloat constructer called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _FixedPoint(copy._FixedPoint){
	std::cout << "\033[0;32mCopy constructer called\033[0m" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src){
	std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	if (this != &src)
		_FixedPoint = src.getRawBits();
	return *this;
}

Fixed& Fixed::operator=(const int src){
	std::cout << "\033[0;32mInt assignment operator called\033[0m" << std::endl;
	_FixedPoint = src << NumberOfBits;
	return *this;
}

Fixed& Fixed::operator=(const float src){
	std::cout << "\033[0;32mFloat assignment operator called\033[0m" << std::endl;
	_FixedPoint = roundf(src * (1 << NumberOfBits));
	return *this;
}

Fixed::~Fixed(){
	std::cout << "\033[1;31mDefault deconstructor called\033[0m" << std::endl;
}

/**************************************************************/
/*                      Compare Operator                      */
/**************************************************************/

bool	Fixed::operator==(const Fixed& src){
	if (_FixedPoint == src._FixedPoint)
		return 1;
	return 0;
}

bool	Fixed::operator!=(const Fixed& src){
	if (_FixedPoint == src._FixedPoint)
		return 0;
	return 1;
}

bool	Fixed::operator<(const Fixed& src){
	if (_FixedPoint < src._FixedPoint)
		return 1;
	return 0;
}

bool	Fixed::operator>(const Fixed& src){
	if (_FixedPoint < src._FixedPoint)
		return 0;
	return 1;
}

bool	Fixed::operator<=(const Fixed& src){
	if (_FixedPoint <= src._FixedPoint)
		return 1;
	return 0;
}

bool	Fixed::operator>=(const Fixed& src){
	if (_FixedPoint <= src._FixedPoint)
		return 0;
	return 1;
}

/**************************************************************/
/*                    Arithmetic Operator                     */
/**************************************************************/

Fixed Fixed::operator+(const Fixed& src) const{
	return Fixed(_FixedPoint + src._FixedPoint);
}

Fixed Fixed::operator-(const Fixed& src) const{
	return Fixed(_FixedPoint - src._FixedPoint);
}

Fixed Fixed::operator*(const Fixed& src) const{
	return Fixed(_FixedPoint * src._FixedPoint >> NumberOfBits);
}

Fixed Fixed::operator/(const Fixed& src) const{
	if (src._FixedPoint == 0)
	{
		std::cout << "\033[1;31mError: Division by zero\033[0m" << std::endl;
		return Fixed(0);
	}
	return Fixed(_FixedPoint / src._FixedPoint << NumberOfBits);
}

/**************************************************************/
/*                Increment/Decrement Operator                */
/**************************************************************/

Fixed& Fixed::operator++(){
	_FixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed ret(*this);
	_FixedPoint++;
	return ret;
}

Fixed& Fixed::operator--(){
	_FixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed ret(*this);
	_FixedPoint--;
	return ret;
}

/**************************************************************/
/*                      Member Functions                      */
/**************************************************************/

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

Fixed& Fixed::min(Fixed& ref1, Fixed& ref2){
	if (ref1._FixedPoint < ref2._FixedPoint)
		return const_cast<Fixed&>(ref1);
	return const_cast<Fixed&>(ref2);
}

Fixed& Fixed::min(const Fixed& ref1, const Fixed& ref2){
	if (ref1._FixedPoint < ref2._FixedPoint)
		return const_cast<Fixed&>(ref1);
	return const_cast<Fixed&>(ref2);
}

Fixed& Fixed::max(Fixed& ref1, Fixed& ref2){
	if (ref1._FixedPoint > ref2._FixedPoint)
		return const_cast<Fixed&>(ref1);
	return const_cast<Fixed&>(ref2);
}

Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2){
	if (ref1._FixedPoint > ref2._FixedPoint)
		return const_cast<Fixed&>(ref1);
	return const_cast<Fixed&>(ref2);
}

/**************************************************************/
/*                      Non Member Functions                  */
/**************************************************************/

std::ostream& operator<<(std::ostream& os, const Fixed& src){
	os << src.toFloat();
	return os;
}
