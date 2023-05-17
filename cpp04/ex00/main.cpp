/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:51:53 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 17:32:34 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(){
	Animal*	puppy = new Dog();
	Animal*	kitty = new Cat();
	
	puppy->makeSound();
	kitty->makeSound();
	delete puppy;
	delete kitty;
}
