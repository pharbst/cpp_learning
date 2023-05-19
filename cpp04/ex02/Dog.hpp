/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:15 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 16:59:33 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(void);
		Dog(Dog const &old);
		Dog& operator=(const Dog& old);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
};

#endif