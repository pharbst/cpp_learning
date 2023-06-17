/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:56:58 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/17 17:38:46 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {
}

AMateria::AMateria(const AMateria& ref) {
	*this = ref;
}

AMateria& AMateria::operator=(const AMateria& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

AMateria::~AMateria() {
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

std::string&	AMateria::getType() {
	return _type;
}