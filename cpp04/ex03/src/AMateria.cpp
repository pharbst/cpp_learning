/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:58 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 17:18:04 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {
}

AMateria::~AMateria() {
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

std::string&	AMateria::getType() {
	return _type;
}