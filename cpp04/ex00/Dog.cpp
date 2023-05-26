/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:58 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 15:03:26 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(std::string("Dog")){
	std::cout << "\033[1;32mDog Default Constructor called\033[0m" << std::endl;
}

Dog::Dog(Dog const &old){
	std::cout << "\033[1;32mDog Copy Constructor called\033[0m" << std::endl;
	*this = old;
}

Dog& Dog::operator=(const Dog& old){
	std::cout << "\033[1;32mDog Assignation called\033[0m" << std::endl;
	Animal::operator=(old);
	return *this;
}

Dog::~Dog(void){
	std::cout << "\033[1;31mDog Destructor called\033[0m" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "\033[1;33mWuff\033[0m" << std::endl;
}
