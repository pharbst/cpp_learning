/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:46:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 14:47:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// constructor
Weapon::Weapon(std::string type)
{
	this->_type = type;
}

// destructor
Weapon::~Weapon()
{}

// member functions
std::string const	&Weapon::getType()
{
	return (this->_type);
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}
