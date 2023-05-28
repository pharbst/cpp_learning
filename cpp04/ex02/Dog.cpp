/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:58 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/28 15:46:09 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(std::string("Dog")){
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(Dog const &old) : Animal(old){
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = old;
}

Dog& Dog::operator=(const Dog& old){
	std::cout << "Dog Assignation called" << std::endl;
	Animal::operator=(old);
	return *this;
}

Dog::~Dog(void){
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "Wuff" << std::endl;
}
