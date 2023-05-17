/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:20:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 16:56:40 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &old);
		Animal& operator=(const Animal& old);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif