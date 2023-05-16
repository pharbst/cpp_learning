/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:35:24 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 18:25:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "\033[0;32mDefault Constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
	std::cout << "\033[0;32mConstructor called\033[0m" << std::endl;
	_name = name;
}

ScavTrap::~ScavTrap(void){
	std::cout << "\033[1;31mDestructor called\033[0m" << std::endl;
}
