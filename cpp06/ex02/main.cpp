/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:10:57 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/20 16:36:30 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base*	generate(void) {
	srand(static_cast<unsigned>(time(NULL)));
	
	int		rand = std::rand() % 3;
	if (rand == 0)
		return (new A);
	else if (rand == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p) {
	if (A* Aptr = dynamic_cast<A*>(p)) {
		std::cout << "A was created." << std::endl;
		(void)Aptr;
	}
	else if (B* Bptr = dynamic_cast<B*>(p)) {
		std::cout << "B was created." << std::endl;
		(void)Bptr;
	}
	else if (C* Cptr = dynamic_cast<C*>(p)) {
		std::cout << "C was created." << std::endl;
		(void)Cptr;
	}
	else {
		std::cout << "Unknown class." << std::endl;
	}
}

void	identify(Base& p) {
	identify(&p);
}

int		main() {
	Base*	something = generate();
	identify(something);
	identify(*something);
	delete something;
}