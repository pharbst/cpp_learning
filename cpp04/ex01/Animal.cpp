/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:27:00 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Undefined Animal"){
	std::cout << "\033[1;32mAnimal Default Constructor called\033[0m" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "\033[1;32mAnimal Constructor called\033[0m" << std::endl;
}

Animal::Animal(Animal const &old) : _type(old.getType()){
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal(void){
	std::cout << " ╚\033[0;31mAnimal Destructor called\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal& old){
	std::cout << "Animal Assignation called" << std::endl;
	this->_type = old.getType();
	return *this;
}

void	Animal::makeSound(void) const{
	std::cout << "Undefined Sound" << std::endl;
}

std::string	Animal::getType(void) const{
	return _type;
}
