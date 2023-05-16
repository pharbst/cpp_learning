/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:42:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 13:20:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor
Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

// destructor
Zombie::~Zombie()
{
	std::cout << _name << " got a headshot" << std::endl;
}

// member functions
void	Zombie::announce()
{
	std::cout << this->_name << ": Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
