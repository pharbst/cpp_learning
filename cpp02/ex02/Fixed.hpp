/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/22 14:21:50 by pharbst          ###   ########.fr       */
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
		Fixed& operator = (const Fixed& src);
		Fixed& operator = (const int src);
		Fixed& operator = (const float src);
		~Fixed();

		bool operator == (const Fixed& src);
		bool operator != (const Fixed& src);
		bool operator > (const Fixed& src);
		bool operator < (const Fixed& src);
		bool operator <= (const Fixed& src);
		bool operator >= (const Fixed& src);

		Fixed operator + (const Fixed& src) const;
		Fixed operator - (const Fixed& src) const;
		Fixed operator * (const Fixed& src) const;
		Fixed operator / (const Fixed& src) const;

		Fixed& operator ++ ();
		Fixed operator ++ (int);
		Fixed& operator -- ();
		Fixed operator -- (int);

		static Fixed& min(Fixed& ref1, Fixed& ref2);
		static Fixed& min(const Fixed& ref1, const Fixed& ref2);
		static Fixed& max(Fixed& ref1, Fixed& ref2);
		static Fixed& max(const Fixed& ref1, const Fixed& ref2);
		int					toInt(void) const;
		float				toFloat(void) const;
		static int const	NumberOfBits = 8;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					_FixedPoint;
};

	std::ostream& operator << (std::ostream& os, const Fixed &src);

#endif