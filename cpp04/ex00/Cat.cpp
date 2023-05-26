/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:13 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 15:07:55 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(std::string("Cat")){
	std::cout << "\033[1;32mCat Default Constructor called\033[0m" << std::endl;
}

Cat::Cat(Cat const &old) : Animal(old){
	std::cout << "\033[1;32mCat Copy Constructor called\033[0m" << std::endl;
	*this = old;
}

Cat& Cat::operator=(const Cat& old){
	std::cout << "\033[1;32mCat Assignation called\033[0m" << std::endl;
	Animal::operator=(old);
	return *this;
}

Cat::~Cat(void){
	std::cout << "\033[1;31mCat Destructor called\033[0m" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "\033[1;33mMiauuu\033[0m" << std::endl;
}
