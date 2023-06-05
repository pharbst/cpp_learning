/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:29:38 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/05 16:48:12 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src){
	for (int i = 0; i < 4; i++)
		_materia[i] = src._materia[i];
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)
		if (!_materia[i]) {
			_materia[i] = m;
			return ;
		}
	std::cout << "MateriaSource is full Materia gets deleted" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++)
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	return (NULL);
}
