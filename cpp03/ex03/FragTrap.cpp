/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:45:00 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/24 14:50:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[1;32mFragTrap Default Constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[1;32mFragTrap Constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref){
	std::cout << "\033[1;32mFragTrap Copy Constructor called\033[0m" << std::endl;
	*this = ref;
}

FragTrap&	FragTrap::operator=(const FragTrap& ref){
	std::cout << "\033[0;32mFragTrap Copy assignment operator called\033[0m" << std::endl;
	ClapTrap::operator=(ref);
	return *this;
}

FragTrap::~FragTrap(void){
	std::cout << "\033[1;31mFragTrap Destructor called\033[0m" << std::endl;
}

void	FragTrap::attack(void){
	std::cout << "\033[1;35mFragTrap " << _name << " attacks " << "target" << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "\033[1;35mFragTrap " << _name << " wants to high five you!\033[0m" << std::endl;
}
