/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:25:57 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 19:25:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(const Ice& ref) : AMateria(ref){
}

Ice::~Ice(){
}

AMateria* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "ice:	* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
