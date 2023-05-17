/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 17:25:11 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Undefined WrongAnimal"){
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &old) : _type(old.getType()){
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& old){
	std::cout << "WrongAnimal Assignation called" << std::endl;
	this->_type = old.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "Undefined Sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return _type;
}
