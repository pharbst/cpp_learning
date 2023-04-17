/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:49:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 15:00:05 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// constructor
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

// destructor
HumanA::~HumanA()
{}

// member functions
void	HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
