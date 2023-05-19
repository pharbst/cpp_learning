/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:34:13 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:25:53 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(std::string("Cat")), _brain(new Brain()){
	std::cout << " ╚\033[1;35mCat Default Constructor called\033[0m" << std::endl;
	// _brain = new Brain();
	_brain->setIdea(0, "Cat Idea 1");
}

Cat::Cat(const Cat& ref) : Animal(ref), _brain(new Brain()){
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref){
	std::cout << "Cat Assignation called" << std::endl;
	if (this != &ref){
		Animal::operator=(ref);
		*_brain = *ref._brain;
	}
	return *this;
}

Cat::~Cat(void){
	std::cout << "\033[1;31mCat Destructor called\033[0m" << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const{
	std::cout << "Miauuu" << std::endl;
}

void	Cat::PrintIdeas(void) const{
	for (int i = 0; std::string(_brain->getIdea(i)) != ""; i++)
		std::cout << _brain->getIdea(i) << std::endl;
}
