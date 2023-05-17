/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:32:45 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 09:59:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**************************************************************/
/*                     Constructors                           */
/**************************************************************/

FragTrap::FragTrap(void){
	std::cout << "\033[0;32mFragTrap Default Constructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ScavTrap(name){
	std::cout << "\033[0;32mFragTrap Constructor called\033[0m" << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "\033[1;31mFragTrap Destructor called\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ScavTrap(ref){
	std::cout << "\033[0;32mFragTrap Copy Constructor called\033[0m" << std::endl;
	*this = ref;
}

FragTrap& FragTrap::operator=(const FragTrap& ref){
	std::cout << "\033[0;32mFragTrap Copy assignment operator called\033[0m" << std::endl;
	if (this != &ref)
		ClapTrap::operator=(ref);
	return (*this);
}

/**************************************************************/
/*                      Member Functions                      */
/**************************************************************/

void	FragTrap::highFivesGuys(void){
	std::cout << getName() << " requests a high five!" << std::endl;
}
