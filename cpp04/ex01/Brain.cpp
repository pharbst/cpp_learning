/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:06:23 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:32:38 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "╚\033[1;36mBrain Default Constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain& ref){
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = ref;
}

Brain::~Brain(void){
	std::cout << "╚\033[0;31mBrain Destructor called\033[0m" << std::endl;
}

Brain& Brain::operator=(const Brain& ref){
	std::cout << "Brain Assignation called" << std::endl;
	if (this != &ref)
		for (int i = 0; i < 100; i++)
			_ideas[i] = ref._ideas[i];
	return *this;
}

void	Brain::setIdea(int i, std::string idea){
	if (i < 0 || i > 99)
		std::cout << "Index out of range" << std::endl;
	else
		_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const{
	if (i < 0 || i > 99)
		return "Index out of range";
	else
		return _ideas[i];
}
