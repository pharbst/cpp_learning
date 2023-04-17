/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:53:43 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 14:55:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// constructor
HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

// destructor
HumanB::~HumanB()
{}

// member functions
void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
