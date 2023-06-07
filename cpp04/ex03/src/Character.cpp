/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/08 01:17:41 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

const std::string&	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	std::cout << "Inventory is full Materia gets destroyed" << std::endl;
	delete m;
}

void	Character::unequip(int idx) {
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	_inventory[idx]->use(target);
}
