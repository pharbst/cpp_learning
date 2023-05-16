/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:02:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 16:27:29 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
	std::cout << "\003[0;32mDefault Constructor called\033[0m" << std::endl;
	_name = "Default";
	_hitpoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "\033[0;32mConstructor called\033[0m" << std::endl;
	_name = name;
	_hitpoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap(void){
	std::cout << "\033[1;31mDestructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & ref){
	std::cout << "\033[0;32mCopy Constructor called\033[0m" << std::endl;
	*this = ref;
}

ClapTrap& ClapTrap::operator = (ClapTrap const & ref){
	std::cout << "\033[0;32mCopy assignment operator called\033[0m" << std::endl;
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const & target){
	std::cout << "\033[0;33mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "\033[0;33mClapTrap " << this->_name << " takes " << amount << " points of damage!\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "\033[0;33mClapTrap " << this->_name << " is repaired for " << amount << " points of damage!\033[0m" << std::endl;
	_energyPoints--;
}
