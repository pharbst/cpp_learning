/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:13 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/28 15:45:46 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(std::string("Cat")){
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(Cat const &old) : Animal(old){
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = old;
}

Cat& Cat::operator=(const Cat& old){
	std::cout << "Cat Assignation called" << std::endl;
	Animal::operator=(old);
	return *this;
}

Cat::~Cat(void){
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "Miauuu" << std::endl;
}
