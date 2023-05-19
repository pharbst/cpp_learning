/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:17:52 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 17:31:24 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void){
	Animal*	animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++){
		if (Dog* dog = dynamic_cast<Dog*>(animals[i]))
			dog->PrintIdeas();
		else if (Cat* cat = dynamic_cast<Cat*>(animals[i]))
			cat->PrintIdeas();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Dog*	testDog = new Dog();
	*testDog = *dynamic_cast<Dog*>(animals[0]);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "testDog Ideas after copy:" << std::endl;
	testDog->PrintIdeas();
	testDog->importIdea(1, "test idea");

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "testDog Ideas after adding new idea:" << std::endl;
	testDog->PrintIdeas();
	std::cout << "the original dog ideas:" << std::endl;
	dynamic_cast<Dog*>(animals[0])->PrintIdeas();


	for (int i = 0; i < 10; i++)
		delete animals[i];

	delete testDog;
}
