/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 16:12:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& ref) : _name(ref._name) {
	for (int i = 0; i < 4; i++) {
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& ref) {
	_name = ref._name;
	for (int i = 0; i < 4; i++) {
		if (ref._inventory[i])
			_inventory[i] = ref._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
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
