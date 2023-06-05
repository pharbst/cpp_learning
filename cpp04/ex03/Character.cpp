/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:33:34 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/05 16:51:01 by pharbst          ###   ########.fr       */
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
	for (int i = 0; i < 20; i++)
		if (this->_floor[i])
			delete this->_floor[i];
}

const std::string& Character::getName() const{
	return (_name);
}

void	Character::equip(AMateria* m){
	int	i = 0;
	while (_inventory[i] != NULL && i < 4)
		i++;
	if (i == 4){
		addFloor(m);
		return ;
	}
	removeFloor(m);
	_inventory[i] = m;
}

void	Character::unequip(int index){
	if (_inventory[index] == NULL)
		return ;
	addFloor(_inventory[index]);
	_inventory[index] = NULL;
	return ;
}

void	Character::addFloor(AMateria* m){
	int	i = 0;
	while (_floor[i] != NULL && i < 20)
		i++;
	if (i == 20) {
		std::cout << "Floor is full 1st Materia now despawns" << std::endl;
		removeFloor(_floor[0]);
		return ;
	}
	_floor[i] = m;
}

void	Character::removeFloor(AMateria* m){
	for (int i = 0; i < 20; i++){
		if (_floor[i] == m){
			delete _floor[i];
			for (int j = i; j < 20; j++)
				_floor[j] = _floor[j + 1];
			return ;
		}
	}
}

void	Character::use(int index, ICharacter& target){
	if (index < 0 || index > 3 || _inventory[index] == NULL)
		return ;
	_inventory[index]->use(target);
}
