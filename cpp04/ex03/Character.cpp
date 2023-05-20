/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:34 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 18:00:14 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

const std::string& Character::getName() const{
	return (_name);
}

AMateria*	Character::equip(AMateria* m){
	for (int i = 0; i < 4 && _inventory[i] != NULL; i++)
		if (i < 4 && _inventory[i] == NULL){
			_inventory[i] = m;
			return NULL;
		}
	return m;
}

AMateria*	Character::unequip(int index){
	if (_inventory[index] == NULL)
		return NULL;
	AMateria*	ret = _inventory[index];
	_inventory[index] = NULL;
	return ret;
}

void	Character::use(int index, ICharacter& target){
	_inventory[index]->use(target);
}
