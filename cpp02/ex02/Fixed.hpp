/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/15 03:39:41 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(int const src);
		Fixed(float const src);
		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed &src);

		int operator == (const Fixed& src);
		int operator != (const Fixed& src);
		int operator > (const Fixed& src);
		int operator < (const Fixed& src);
		int operator <= (const Fixed& src);
		int operator >= (const Fixed& src);

		Fixed& operator + (const Fixed& src);
		Fixed& operator - (const Fixed& src);
		Fixed& operator * (const Fixed& src);
		Fixed& operator / (const Fixed& src);

		Fixed& operator ++ (const Fixed& src);
		Fixed& operator ++ (const Fixed& src);
		Fixed& operator -- (const Fixed& src);
		Fixed& operator -- (const Fixed& src);
		~Fixed();

		int					toInt(void) const;
		float				toFloat(void) const;
		static int const	NumberOfBits = 8;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					FixedPoint;
};

	std::ostream& operator << (std::ostream& os, const Fixed &src);

#endif