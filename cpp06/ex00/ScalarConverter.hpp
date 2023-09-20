/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:46:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/20 14:44:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstdlib>
# include <cmath>
# include <iostream>
# include <string>
# include <climits>
# include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		static void			_char(char c);
		static void			_int(long i);
		static void			_float(float f);
		static void			_double(double d);
	public:
		static void			convert(std::string input);
};

#endif
