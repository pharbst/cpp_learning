/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:35:24 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 09:25:34 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**************************************************************/
/*                     Constructors                           */
/**************************************************************/

ScavTrap::ScavTrap(void){
	std::cout << "\033[0;32mScavTrap Default Constructor called\033[0m" << std::endl;
	_guardGateMode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "\033[0;32mScavTrap Constructor called\033[0m" << std::endl;
	_guardGateMode = false;
}

ScavTrap::~ScavTrap(void){
	std::cout << "\033[1;31mScavTrap Destructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & ref){
	std::cout << "\033[0;32mScavTrap Copy Constructor called\033[0m" << std::endl;
	*this = ref;
}

ScavTrap& ScavTrap::operator = (ScavTrap const & ref){
	std::cout << "\033[0;32mScavTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &ref)
	{
		_guardGateMode = ref._guardGateMode;
		ClapTrap::operator=(ref);
	}
	return (*this);
}

/**************************************************************/
/*                      Member Functions                      */
/**************************************************************/

void	ScavTrap::attack(ScavTrap& target){
	if (_guardGateMode)
		std::cout << getName() << " cannot attack while in guardGateMode!" << std::endl;
	else{
		ClapTrap::attack(target.getName());
		target.takeDamage(getAttackDamage());
	}
}

void	ScavTrap::takeDamage(int AtkDmg){
	if (_guardGateMode){
		std::cout << getName() << " DMG is reduced by 50% while in guardGateMode!" << std::endl;
		ClapTrap::takeDamage(AtkDmg / 2);
	}
	else
		ClapTrap::takeDamage(AtkDmg);
}

void	ScavTrap::beRepaired(){
	if (_guardGateMode){
		std::cout << ClapTrap::getName() << " repair whithout energy while in guardGateMode!" << std::endl;
		ClapTrap::beRepaired(ClapTrap::getRepairStrength());
		ClapTrap::gainEnergy(1);
	}
	else
		ClapTrap::beRepaired(ClapTrap::getRepairStrength());
}

void	ScavTrap::guardGate(){
	if (_guardGateMode)
		_guardGateMode = false;
	else
		_guardGateMode = true;
}
