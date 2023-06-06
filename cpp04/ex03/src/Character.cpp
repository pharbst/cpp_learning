/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/06 17:31:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
}

Character::~Character() {
}

const std::string&	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!_inventory[i])
			_inventory[i] = m;
}

void	Character::unequip(int idx) {
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	_inventory[idx]->use(target);
}
