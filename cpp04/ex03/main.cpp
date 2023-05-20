/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:06:29 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 19:24:39 by pharbst          ###   ########.fr       */
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
	tmp2 = new Cure();
	me->equip(tmp);
	me->equip(tmp2);
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	return 0;
}
