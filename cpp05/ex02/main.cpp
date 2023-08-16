/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:07:02 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/16 08:08:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Fix the concrete classes
// write a function in the Aform base class
// to call the execute functions of the concrete classes
// its prettier

// rename the execute functions of the derived classes and implement the execute function
// in the base class and call the action function of the derived class also add the not signed exception to the base classw

int main(void) {
	AForm *Formular[3];

	Formular[0] = new ShrubberyCreationForm("Home");
	Formular[1] = new RobotomyRequestForm("Pfff");
	Formular[2] = new PresidentialPardonForm("Your moma");

	Bureaucrat Larry("Larry", 150);
	Bureaucrat Ulli("Ulli", 90);
	Bureaucrat Herta("Herta", 50);
	Bureaucrat Jürgen("Jürgen", 30);
	Bureaucrat Ute("Ute", 20);

	std::cout << "Bureaucrats created" << std::endl;
	Formular[0]->execute(Ulli);
	std::cout << "Ulli tryed to execute Shrubbery" << std::endl;
	Formular[0]->beSigned(Larry);
	std::cout << "Larry tryed to sign shrubbery" << std::endl;
	Formular[0]->beSigned(Ulli);
	std::cout << "Ulli tryed to sign shrubbery" << std::endl;
	Formular[0]->execute(Larry);
	std::cout << "Larry tryed to execute Shrubbery" << std::endl;
	Formular[0]->execute(Ulli);
	std::cout << "Ulli tryed to execute Shrubbery" << std::endl;

	Formular[1]->execute(Ulli);
	std::cout << "Ulli tryed to execute Robotomy" << std::endl;
	Formular[1]->beSigned(Larry);
	std::cout << "Larry tryed to sign Robotomy" << std::endl;
	Formular[1]->beSigned(Ulli);\
	std::cout << "Ulli tryed to sign Robotomy" << std::endl;
	Formular[1]->beSigned(Herta);
	std::cout << "Herta tryed to sign Robotomy" << std::endl;
	Formular[1]->execute(Larry);
	std::cout << "Larry tryed to execute Robotomy" << std::endl;
	Formular[1]->execute(Ulli);
	std::cout << "Ulli tryed to execute Robotomy" << std::endl;
	Formular[1]->execute(Herta);
	std::cout << "Herta tryed to execute Robotomy" << std::endl;
	Formular[1]->execute(Jürgen);
	std::cout << "Jürgen tryed to execute Robotomy" << std::endl;
	Formular[1]->execute(Ute);
	std::cout << "Ute tryed to execute Robotomy" << std::endl;

	Formular[2]->execute(Ulli);
	std::cout << "Ulli tryed to execute Presidential" << std::endl;
	Formular[2]->beSigned(Larry);
	std::cout << "Larry tryed to sign Presidential" << std::endl;
	Formular[2]->beSigned(Ulli);
	std::cout << "Ulli tryed to sign Presidential" << std::endl;
	Formular[2]->beSigned(Herta);
	std::cout << "Herta tryed to sign Presidential" << std::endl;
	Formular[2]->execute(Larry);
	std::cout << "Larry tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Ulli);
	std::cout << "Ulli tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Herta);
	std::cout << "Herta tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Jürgen);
	std::cout << "Jürgen tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Ute);
	std::cout << "Ute tryed to execute Presidential" << std::endl;
	
	return 0;
}
