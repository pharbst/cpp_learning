/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:02:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 09:03:51 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**************************************************************/
/*                     Constructors                           */
/**************************************************************/

ClapTrap::ClapTrap(void){
	std::cout << "\033[0;32mClapTrap Default Constructor called\033[0m" << std::endl;
	_name = "Default";
	_hitpoints = 100;
	_maxHitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_repairStrength = 10;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "\033[0;32mClapTrap Constructor called\033[0m" << std::endl;
	_name = name;
	_hitpoints = 100;
	_maxHitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_repairStrength = 10;
}

ClapTrap::ClapTrap(ClapTrap const & ref){
	std::cout << "\033[0;32mClapTrap Copy Constructor called\033[0m" << std::endl;
	*this = ref;
}

ClapTrap& ClapTrap::operator = (ClapTrap const & ref){
	std::cout << "\033[0;32mClapTrap Copy assignment operator called\033[0m" << std::endl;
	this->_name = ref._name;
	this->_hitpoints = ref._hitpoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void){
	std::cout << "\033[1;31mClapTrap Destructor called\033[0m" << std::endl;
}

/**************************************************************/
/*                      Member Functions                      */
/**************************************************************/

void			ClapTrap::attack(std::string const & target){
	std::cout << "\033[0;33mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
	_energyPoints--;
}

void			ClapTrap::takeDamage(unsigned int amount){
	std::cout << "\033[0;33mClapTrap " << this->_name << " takes " << amount << " points of damage!\033[0m" << std::endl;
	_hitpoints -= amount;
}

void			ClapTrap::beRepaired(unsigned int amount){
	if (amount + _hitpoints > _maxHitpoints){
		std::cout << "\033[0;33m" << this->_name << " is repaired for " << _maxHitpoints - _hitpoints << " points of damage!\033[0m" << std::endl;
		_hitpoints = _maxHitpoints;
	}
	else{
		_hitpoints += amount;
		std::cout << "\033[0;33m" << this->_name << " is repaired for " << amount << " points of damage!\033[0m" << std::endl;
	}
	_energyPoints--;
}

void			ClapTrap::gainEnergy(unsigned int amount){
	_energyPoints += amount;
}

/**************************************************************/
/*                         Accessors                          */
/**************************************************************/

std::string		ClapTrap::getName(void) const{
	return (this->_name);
}

unsigned int	ClapTrap::getHitpoints(void) const{
	return (this->_hitpoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const{
	return (this->_attackDamage);
}

unsigned int	ClapTrap::getRepairStrength(void) const{
	return (this->_repairStrength);
}

/**************************************************************/
/*                         Functions                          */
/**************************************************************/

std::ostream&	operator << (std::ostream& out, ClapTrap const & ref){
	std::cout << "\033[0;35m" << ref.getName() << " has " << ref.getHitpoints() << " hitpoints, " << ref.getRepairStrength() << " repairStrength, " << ref.getEnergyPoints() << " energy points and " << ref.getAttackDamage() << " attack damage!\033[0m" << std::endl;
	return (out);
}
