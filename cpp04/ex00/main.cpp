/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:53 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/26 15:12:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(){
	Animal*	puppy = new Dog();
	Animal*	kitty = new Cat();
	Animal* animal = new Animal();
	
	puppy->makeSound();
	kitty->makeSound();
	animal->makeSound();
	delete puppy;
	delete kitty;
	delete animal;
	std::cout << std::endl;
	std::cout << std::endl;
	WrongAnimal*	wrongkitty = new WrongCat();
	WrongAnimal*	wronganimal = new WrongAnimal();
	
	wrongkitty->makeSound();
	wronganimal->makeSound();
	delete wrongkitty;
	delete wronganimal;
	return 0;
}
