/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:13 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 17:22:11 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal(std::string("WrongCat")){
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &old){
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = old;
}

WrongCat& WrongCat::operator=(const WrongCat& old){
	std::cout << "WrongCat Assignation called" << std::endl;
	WrongAnimal::operator=(old);
	return *this;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Miauuu" << std::endl;
}
