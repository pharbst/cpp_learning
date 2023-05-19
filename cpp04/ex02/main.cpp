/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:53 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:49:29 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(){
	Animal*	puppy = new Dog();
	Animal*	kitty = new Cat();
	// Animal*	Accident = new Animal();
	
	puppy->makeSound();
	kitty->makeSound();
	delete puppy;
	delete kitty;
	// delete Accident;
}
