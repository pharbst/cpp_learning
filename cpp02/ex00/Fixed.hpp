/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:03:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/11 10:32:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed& src);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int					FixedPoint;
		static int const	NumberOfBits = 8;
};

#endif