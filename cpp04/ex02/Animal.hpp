/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:20:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:43:30 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#ifndef _IOSTREAM_
# define _IOSTREAM_
#include <iostream>
#endif

class Animal{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &old);
		Animal& operator=(const Animal& old);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif