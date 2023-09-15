/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:46:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/15 14:36:12 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;

		static void			convert(std::string input);
};

#endif
