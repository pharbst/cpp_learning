/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:20:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 15:02:37 by pharbst          ###   ########.fr       */
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
		Animal(Animal const &ref);
		Animal& operator=(const Animal& ref);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif