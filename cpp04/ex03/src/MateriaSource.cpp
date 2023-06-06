/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:32:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/06 17:58:36 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	int	i = -1;
	while (++i < 4)
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	if (i == 4) {
		std::cout << "MateriaSource is full Materia gets destroyed" << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	int i = 0;
	while (i < 4) {
		if (_inventory[i]->getType == type)
			return _inventory[i]->clone;
		i++;
	}
}
