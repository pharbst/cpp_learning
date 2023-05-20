/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:06:29 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 18:11:38 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

int main(){
	AMateria*	tmp;
	AMateria*	tmp2;

	Character*	me = new Character("me");
	Character*	bob = new Character("bob");
	
	tmp = new Ice();
	me->equip(tmp);
	tmp2 = new Cure();
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete tmp;
	delete tmp2;
	return 0;
}
