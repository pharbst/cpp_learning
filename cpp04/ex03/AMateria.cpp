/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:15:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 16:24:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type){
}

AMateria::~AMateria(){
}

void	use(ICharacter& target){
	(void)target;
}

void	AMateria::use(ICharacter& target){
	(void)target;
}
