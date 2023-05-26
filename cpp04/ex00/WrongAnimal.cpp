/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:28:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 15:08:22 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Undefined WrongAnimal"){
	std::cout << "\033[1;32mWrongAnimal Default Constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "\033[1;32mWrongAnimal Constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &old) : _type(old.getType()){
	std::cout << "\033[1;32mWrongAnimal Copy Constructor called\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "\033[0;31mWrongAnimal Destructor called\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& old){
	std::cout << "\033[1;32mWrongAnimal Assignation called\033[0m" << std::endl;
	this->_type = old.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "\033[0;33mUndefined Sound\033[0m" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return _type;
}
