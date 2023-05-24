/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:45:00 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/24 13:34:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "\033[1;32mScavTrap Default Constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "\033[1;32mScavTrap Constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref){
	std::cout << "\033[1;32mScavTrap Copy Constructor called\033[0m" << std::endl;
	*this = ref;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ref){
	std::cout << "\033[0;32mScavTrap Copy assignment operator called\033[0m" << std::endl;
	ClapTrap::operator=(ref);
	return *this;
}

ScavTrap::~ScavTrap(void){
	std::cout << "\033[1;31mScavTrap Destructor called\033[0m" << std::endl;
}

void	ScavTrap::attack(void){
	std::cout << "\033[1;35mScavTrap " << _name << " attacks " << "target" << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << "\033[1;35mScavTrap " << _name << " has entered in Gate keeper mode\033[0m" << std::endl;
}
