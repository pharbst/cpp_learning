/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:21:40 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 09:50:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// #include <unistd.h>

int	main(void){
	FragTrap a("ScrapTrap");
	FragTrap b("Robot");

	std::cout << a << std::endl << b << std::endl;

	std::cout << a.getName() << " and " << b.getName() << " entering the arena" << std::endl << std::endl;
	// sleep(3);
	std::cout << "Battle starts in 3" << std::endl;
	// sleep(1);
	std::cout << "\033[1A\033[2K\rBattle starts in 2" << std::endl;
	// sleep(1);
	std::cout << "\033[1A\033[2K\rBattle starts in 1" << std::endl;
	// sleep(1);
	std::cout << "\033[1A\033[2K\rFIGHT!" << std::endl << std::endl;
	// sleep(1);
	std::cout << a.getName() << " starts an attack" << std::endl;
	a.attack(b);
	// sleep(2);
	std::cout << "that was a hard hit for " << b.getName() << std::endl;
	// sleep(1);
	std::cout << b.getName() << " starts a counter attack" << std::endl;
	b.attack(a);
	// sleep(2);
	std::cout << "what a start of the battle" << std::endl;
	// sleep(1);
	std::cout << a.getName() << " is attacking again" << std::endl;
	a.attack(b);
	// sleep(2);
	std::cout << "but " << b.getName() << " is still standing" << std::endl;
	// sleep(1);
	b.guardGate();
	std::cout << "ohh " << b.getName() << " sets himself in guardGateMode" << std::endl;
	b.beRepaired();
	std::cout << "and repairs himself, will this gets him the advantage he needs?" << std::endl;
	// sleep(1);
	std::cout << a.getName() << " is attacking again" << std::endl;
	a.attack(b);
	// sleep(2);
	std::cout << "smart way of " << b.getName() << " to block the attack" << std::endl;
	// sleep(1);
	b.beRepaired();
	std::cout << b.getName() << " repairs again" << std::endl;
	// sleep(1);
	a.guardGate();
	a.beRepaired();
	std::cout << "and " << a.getName() << " repairs himself and sets himself in guardGateMode" << std::endl;
	// sleep(1);
	b.guardGate();
	b.attack(a);
	std::cout << b.getName() << " goes back to normal mode and attacks " << a.getName() << std::endl;

	std::cout << std::endl << "The battle is over" << std::endl;

	std::cout << a << std::endl << b << std::endl;
	if (a.getHitpoints() > b.getHitpoints()){
		std::cout << a.getName() << " is the winner!!!" << std::endl;
		b.highFivesGuys();
	}
	else if (a.getHitpoints() < b.getHitpoints()){
		std::cout << b.getName() << " is the winner!!!" << std::endl;
		a.highFivesGuys();
	}
	else{
		std::cout << "It's a draw!!!" << std::endl;
		a.highFivesGuys();
		b.highFivesGuys();
	}
}