/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:33 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/01 23:22:29 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <exception>

class unknownClassException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class Base {
	public:
		virtual ~Base(void);
};

class Unkonwn : public Base {};

#endif