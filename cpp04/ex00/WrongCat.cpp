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
	std::cout << "\033[0;32mWrongCat Default Constructor called\033[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &old) : WrongAnimal(old){
	std::cout << "\033[0;32mWrongCat Copy Constructor called\033[0m" << std::endl;
	*this = old;
}

WrongCat& WrongCat::operator=(const WrongCat& old){
	std::cout << "\033[0;32mWrongCat Assignation called\033[0m" << std::endl;
	WrongAnimal::operator=(old);
	return *this;
}

WrongCat::~WrongCat(void){
	std::cout << "\033[1;31mWrongCat Destructor called\033[0m" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "\033[1;33mMiauuu\033[0m" << std::endl;
}
