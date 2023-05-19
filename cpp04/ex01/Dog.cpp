/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:58 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:27:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(std::string("Dog")), _brain(new Brain()){
	std::cout << " ╚\033[1;35mDog Default Constructor called\033[0m" << std::endl;
	_brain->setIdea(0, "Dog Idea 1");
}

Dog::Dog(Dog const &ref) : Animal("Dog"), _brain(new Brain()){
	std::cout << "Dog Copy Constructor called" << std::endl;
	_brain = ref._brain;
}

Dog& Dog::operator=(const Dog& ref){
	std::cout << "Dog Assignation called" << std::endl;
	if (this != &ref){
		Animal::operator=(ref);
		*_brain = *ref._brain;
	}
	return *this;
}

Dog::~Dog(void){
	std::cout << "\033[1;31mDog Destructor called\033[0m" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const{
	std::cout << "Wuff" << std::endl;
}

void	Dog::PrintIdeas(void) const{
	for (int i = 0; std::string(_brain->getIdea(i)) != ""; i++)
		std::cout << _brain->getIdea(i) << std::endl;
}

void	Dog::importIdea(int i, std::string idea){
	_brain->setIdea(i, idea);
}
